/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
//#define PROBLEM "problem_name.h"
//#include PROBLEM
//#include <message.h>
//#include <spcppl/dgcj.h>

using namespace std;

class TaskA {
public:
	void solve(std::istream& in, std::ostream& out) {
		//static int testnumber = 0;
		//out << "Case #" << ++testnumber << ": ";

		int x,y,z, t1,t2,t3;
		in >> x >> y >> z >> t1 >> t2 >> t3;
		cerr << abs(x - y) * t1 << ' ' << abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3<<endl;
		if (abs(x - y) * t1 < abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3) {
			out << "NO\n";
		} else {
			out << "YES\n";
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	TaskA solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	in.tie(nullptr);
	out << std::fixed;
	out.precision(20);
	solver.solve(in, out);
	return 0;
}