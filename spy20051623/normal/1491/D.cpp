#include <bits/stdc++.h>
using namespace std;
long long a, b;

bool check() {
	bool f = false;
	int ca = 0, cb = 0;
	while (b) {
		if (a % 2 == 1)
			++ca;
		if (b % 2 == 1)
			++cb;
		if (ca < cb)
			return false;
		a >>= 1;
		b >>= 1;
	}
	return true;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int q;
	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (a > b)
			cout << "NO" << endl;
		else if (a == b)
			cout << "YES" << endl;
		else {
			cout << (check() ? "YES" : "NO") << endl;
		}
	}
	return 0;
}