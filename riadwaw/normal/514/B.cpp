/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <set>
#include <utility>

using namespace std;

class TaskB {
public:
	int gcdg(int x, int y);

	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		set<pair<int, int>> s;
		int x0, y0;
		in >> x0 >> y0;

		for (int i = 0;i < n; ++i) {
			int x, y;
			in >> x >> y;
			x -= x0;
			y -= y0;
			if(x == 0 && y == 0)
				continue;
			int g = gcdg(x, y);
			x /= g;
			y /= g;
			if(x < 0 || x == 0 && y < 0) {
				x = -x;
				y = -y;
			}

			s.insert(make_pair(x, y));
		}
		out << max((int)s.size(), 1);
	}
};

int TaskB::gcdg(int x, int y) {
	while(y) {
		x %= y;
		swap(x, y);
	}
	return x;
}


int main() {
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}