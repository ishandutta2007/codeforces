#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (auto &x : s) cin >> x;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (s[i][j] == s[j][i] || m % 2 == 1) {
				cout << "YES\n";
				for (int k = 0; k <= m; k++)
					cout << (k % 2 ? i : j) + 1 << " ";
				cout << "\n";
				return;
			}
		}
	if (n == 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	int x = -1, y = -1, mid = -1;
	while (x == -1) {
		x = rand() % n, y = rand() % n, mid = rand() % n;
		if (x == y || x == mid || y == mid || s[x][mid] != s[mid][y])
			x = -1;
	}

	for (int i = m / 2 - 1; i >= 0; i--) {
		if (i % 2 == 0) cout << x + 1 << " ";
		else cout << y + 1 << " ";
	}
	cout << mid + 1;
	for (int i = 0; i < m / 2; i++) {
		if (i % 2 == 0) cout << " " << y + 1;
		else cout << " " << x + 1;
	}
	cout << "\n";
}

int main() {
	int t = 1;
#ifdef SERT
	t = 3;
#endif
	cin >> t;
	while (t--)
		solve();
}