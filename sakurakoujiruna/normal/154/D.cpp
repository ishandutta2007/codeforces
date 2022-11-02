#include <bits/stdc++.h>
using namespace std;

const string fi = "FIRST", se = "SECOND", dr = "DRAW";

int main() {
	ios :: sync_with_stdio(false);
	int x1, x2, a, b;
	cin >> x1 >> x2 >> a >> b;
	if(a <= 0 && 0 <= b) {
		if(x1 + a <= x2 && x2 <= x1 + b)
			cout << fi << '\n' << x2 << '\n';
		else
			cout << dr << '\n';
	} else {
		int sgn = 1;
		if(a < 0) {
			a = -a; b = -b; swap(a, b);
			x1 = -x1; x2 = -x2; sgn = -1;
		}
		if(x1 > x2)
			cout << dr << '\n';
		else {
			int t = (x2 - x1) % (a + b);
			if(t == 0)
				cout << se << '\n';
			else if(a <= t && t <= b)
				cout << fi << '\n' << sgn * (x1 + t) << '\n';
			else
				cout << dr << '\n';
		}
	}
	return 0;
}