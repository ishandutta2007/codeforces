/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		std::string s;
		in >> s;
		for(int i = 0; i < s.size(); ++i) {
			if (s[i] >= '5') {
				if(s[i] != '9' || i != 0) {
					s[i] = 9 - (s[i] - '0') + '0';
				}
			}
		}
		out << s;
	}
};


int main() {
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}