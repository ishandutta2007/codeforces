/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s;
		getline(in, s);
		set<int> different;
		for(char c: s) {
			different.insert(c);
		}
		different.erase('{');
		different.erase('}');
		different.erase(',');
		different.erase(' ');
		out << different.size();
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(0);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}