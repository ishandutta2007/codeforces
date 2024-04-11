#include <iostream>
#include <string>

int main(){
	std::string a, b;
	std::cin >> a >> b;
	std::cout << (a != b ? "1" : a.c_str());
	return 0;
}