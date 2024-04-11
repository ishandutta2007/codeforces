#include <cmath>
#include <string>
#include <iostream>
using namespace std;
long long p, x, y, q, ra, rb, a, b;
int main() {
	cin >> p >> x >> y >> q;
	ra = (sqrt(8.0 * p + 1.0 + 1.0e-7) + 1) / 2;
	rb = (sqrt(8.0 * q + 1.0 + 1.0e-7) + 1) / 2;
	string res;
	for (int i = -1; i <= 0 && !res.size(); i++) {
		for (int j = -1; j <= 0 && !res.size(); j++) {
			a = ra + i;
			b = rb + j;
			bool flag = true;
			if (a * (a - 1) != 2 * p) flag = false;
			if (b * (b - 1) != 2 * q) flag = false;
			if (x + y != a * b) flag = false;
			if (a + b == 0) flag = false;
			if (!flag) continue;
			else {
				string ret;
				if (a == 0) ret = string(b, '1');
				else if (b == 0) ret = string(a, '0');
				else ret = string(y / a, '1') + string(a - y % a, '0') + (y % a ? "1" : "") + string(y % a, '0') + string(x / a, '1');
				res = ret;
			}
		}
	}
	cout << (res.size() ? res : "Impossible") << endl;
	return 0;
}