#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int s, x1, x2, t1, t2, p, d;
int main() {
	cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
	if (x1 > x2) x1 = s - x1, x2 = s - x2, p = s - p, d = -d;
	if (d == 1 && x1 < p) {
		cout << min(t2 * (x2 - x1), t1 * (s * 2 + (x2 - p))) << endl;
	}
	else if(d == -1) {
		cout << min(t2 * (x2 - x1), t1 * (x2 + p)) << endl;
	}
	else {
		cout << min(t2 * (x2 - x1), t1 * (x2 - p)) << endl;
	}
	return 0;
}