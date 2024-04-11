#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		c = 0;
		if (b == 1) {
			++b;
			++c;
		}
		while (log(a) / log(b) > log(a) / log(b + 1) + 1) {
			++b;
			++c;
		}
		while (a) {
			a /= b;
			++c;
		}
		cout << c << endl;
	}
	return 0;
}