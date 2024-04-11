#include <bits/stdc++.h>

using namespace std;

int aa[5000], ab[5000];

int q(int x, int y) {
	cout << "? " << x << ' ' << y << '\n';
	fflush(stdout);
	int t;
	cin >> t;
	return t;
}

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		aa[i] = q(i, i);
		ab[i] = q(0, i);
	}
	vector<int> b(n), c(n), res;
	int ans = 0, ff = 0;
	for (int i = 0; i < n; i++) {
		b[0] = i;
		for (int j = 0; j < n; j++)
			c[j] = b[0] ^ ab[j];
		for (int j = 1; j < n; j++)
			b[j] = c[j] ^ aa[j];
		int f = 1;
		for (int j = 0; j < n; j++)
			if (c[b[j]] != j) {
				f = 0;
				break;
			}
		if (f) {
			if (ans == 0)
				res = b;
			ans++;
		}
	}
	cout << "!\n";
	fflush(stdout);
	cout << ans << '\n';
	fflush(stdout);
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';
	fflush(stdout);
}