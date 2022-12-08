#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y, int z) {
	cout << "? " << x << ' ' << y << ' ' << z << endl;
	int p;
	cin >> p;
	if (p == -1) exit(0);
	return p;
}

void solve() {
	int n;
	cin >> n;
	int x = 1, y = 2, z = 3;
	int lst = ask(x, y, z);
	for (int i = 4; i <= n; ++i) {
		int a = ask(x, z, i), b = ask(y, z, i);
		if (a > lst || b > lst) {
			if (a < b) {
				lst = b;
				x = i;
			} else {
				lst = a;
				y = i;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (x != i && y != i && z != i) {
			int p = ask(x, y, i);
			assert(p <= lst);
			if (p == lst) {
				cout << "! " << x << ' ' << y << endl;
				return;
			} else {
				int a = ask(x, z, i), b = ask(y, z, i);
				if (a < b) {
					cout << "! " << y << ' ' << z << endl;
				} else {
					cout << "! " << x << ' ' << z << endl;
				}
				return;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}