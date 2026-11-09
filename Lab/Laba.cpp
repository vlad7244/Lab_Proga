#include <iostream>
#include <windows.h>
#include <bitset>
#include <cstring>

// Коды цветов для текста
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"


int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	// Размеры типов в байтах
	std::cout << BLUE << "Размеры типов в байтах\n" << RESET;
	std::cout << "\nРазмер " << RED << "bool" << RESET << ": " << sizeof(bool) << " байт\n";
	std::cout << "Размер " << RED << "char" << RESET << ": " << sizeof(char) << " байт\n";
	std::cout << "Размер " << RED << "short int" << RESET << ": " << sizeof(short int) << " байт\n";
	std::cout << "Размер " << RED << "int" << RESET << ": " << sizeof(int) << " байт\n";
	std::cout << "Размер " << RED << "long int" << RESET << ": " << sizeof(long int) << " байт\n";
	std::cout << "Размер " << RED << "float" << RESET << ": " << sizeof(float) << " байт\n";
	std::cout << "Размер " << RED << "double" << RESET << ": " << sizeof(double) << " байт\n";
	std::cout << "Размер " << RED << "long double" << RESET << ": " << sizeof(long double) << " байт\n";



	// Двоичное представление целого числа
	std::cout << BLUE << "\nДвоичное представление целого числа\n" << RESET;
	std::cout << "\nВведите число типа int:\n\n";
	
	int n;
	std::cin >> n;

	std::bitset<32> b(n);
	std::cout << "\n" << GREEN << b[31] << RESET;

	for (int i = 30; i >= 0; i--) {
		std::cout << b[i];
		if (i % 4 == 0) {
			std::cout << " ";
		}
	}
	
	std::cout << "\tЗнаковый бит выделен " << GREEN << "зелёным" << RESET << " цветом.\n";

	
	
	// Двоичное представление float
	std::cout << BLUE << "\nДвоичное представление float\n" << RESET;
	std::cout << "\nВведите число типа float:\n\n";
	
	float f;
	std::cin >> f;

	unsigned int bits_f;
	std::memcpy(&bits_f, &f, sizeof(f));

	std::bitset<32> bf(bits_f);
	
	std::cout << "\nЗнак: " << " ";
	std::cout << bf[31] << "\t";
	
	std::cout << "Порядок: ";
	for (int i = 30; i >= 23; i--) {
		std::cout << bf[i];
		if (i == 23) {
			std::cout << "\t";
		}
	}
	
	std::cout << "Мантисса: ";
	for (int i = 22; i >= 0; i--) {
		std::cout << bf[i];
	}
	std::cout << "\n";

	
	
	// Двоичное представление double
	std::cout << BLUE << "\nДвоичное представление double\n" << RESET;
	std::cout << "\nВведите число типа double:\n\n";

	double d;
	std::cin >> d;

	unsigned long long bits_d;
	std::memcpy(&bits_d, &d, sizeof(d));

	std::bitset<64> bd(bits_d);

	std::cout << "\nЗнак: " << " ";
	std::cout << bd[63] << "\t";

	std::cout << "Порядок: ";
	for (int i = 62; i >= 52; i--) {
		std::cout << bd[i];
		if (i == 52) {
			std::cout << "\t";
		}
	}

	std::cout << "Мантисса: ";
	for (int i = 51; i >= 0; i--) {
		std::cout << bd[i];
	}
	std::cout << "\n";
	


	// Изменение произвольного бита
	std::cout << BLUE << "\nИзменение произвольного бита\n" << RESET;
	int type, k, value;
	unsigned long long bin = 0;

	std::cout << "\n1 - int\n2 - float\n3 - double\n\n";
	std::cin >> type;
	std::cout << "\nВведите число:\n\n";
	
	if (type == 1) {
		int num;
		std::cin >> num;
		std::memcpy(&bin, &num, sizeof(num));
		std::cout << "\n" << std::bitset<32>(bin) << "\n\n";
	}
	else if (type == 2) {
		float num;
		std::cin >> num;
		std::memcpy(&bin, &num, sizeof(num));
		std::cout << "\n" << std::bitset<32>(bin) << "\n\n";
	}
	else if (type == 3) {
		double num;
		std::cin >> num;
		std::memcpy(&bin, &num, sizeof(num));
		std::cout << "\n" << std::bitset<64>(bin) << "\n\n";
	}

	std::cout << "Введите номер бита (считая справа c числа ""0""):\n\n";
	std::cin >> k;

	std::cout << "\nВведите новое значение (0 или 1):\n\n";
	std::cin >> value;

	int size = (type == 3) ? 64 : 32;

	if (k < 0 || k >= size || (value != 0 && value != 1)) {
		std::cout << "Ошибка!";
	}

	if (value == 1) {
		bin = bin | (1ULL << k);
	}
	else {
		bin = bin & ~(1ULL << k);
	}

	std::cout << "\nРезултат:\n";

	if (type == 3) {
		std::cout << "\n" << std::bitset<64>(bin) << "\n";
	}
	else {
		std::cout << "\n" << std::bitset<32>(bin) << "\n";
	}



	// Умножение на 2 через битовый сдвиг
	std::cout << "\n" << BLUE << "Умножение на 2 через битовый сдвиг" << RESET << "\n";
	std::cout << "\n" << "Введите целое число:\n\n";
	
	int x;
	std::cin >> x;
	
	int result = x << 1;
	
	std::cout << "\nВаше число умноженное на 2:\n\n" << result << "\n";
}