#include <bits/stdc++.h>
using namespace std;

int p(int x, int y) {
	int r=1;
	while (y--)
		r*=x;
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x, y;
	cin >> x >> y;
	if (x == y || (x*1ll*y == 8 && x+y == 6)) {
		cout << "=";
	} else if (min(x, y) >= 3) {
		if (x > y) {
			cout << "<";
		} else {
			cout << ">";
		}
	} else if (x == 2 && y == 3) {
		cout << "<";
	} else if (x == 3 && y == 2) {
		cout << ">";
	} else if (min(x, y) == 1) {
		cout << (x < y ? "<" : ">");
	} else if (min(x, y) == 2) {
		cout << (x < y ? ">" : "<");
	}
}