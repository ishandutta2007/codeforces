#include <bits/stdc++.h>

using namespace std;

long long f[300005], a[300005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q, m;
	cin >> n >> q >> m;
	f[1] = 1;
	for (int i = 2; i < 300005; ++i) f[i] = (f[i - 1] + f[i - 2]) % m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		a[i] -= p;
		a[i] = (a[i] % m + m) % m;
	}
	int cnt = 0;
	for (int i = n; i >= 2; --i) {
		a[i] -= a[i - 1] + a[i - 2];
		a[i] = (a[i] % m + m) % m;
		if (a[i]) ++cnt;
	}
	if (a[1]) ++cnt;
	while (q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if (c == 'A') {
			if (a[x]) --cnt;
			++a[x];
			a[x] = (a[x] % m + m) % m;
			if (a[x]) ++cnt;
			if (y + 1 <= n) {
				if (a[y + 1]) --cnt;
				a[y + 1] -= f[y - x + 2];
				a[y + 1] = (a[y + 1] % m + m) % m;
				if (a[y + 1]) ++cnt;
			}
			if (y + 2 <= n) {
				if (a[y + 2]) --cnt;
				a[y + 2] -= f[y - x + 1];
				a[y + 2] = (a[y + 2] % m + m) % m;
				if (a[y + 2]) ++cnt;
			}
		} else {
			if (a[x]) --cnt;
			--a[x];
			a[x] = (a[x] % m + m) % m;
			if (a[x]) ++cnt;
			if (y + 1 <= n) {
				if (a[y + 1]) --cnt;
				a[y + 1] += f[y - x + 2];
				a[y + 1] = (a[y + 1] % m + m) % m;
				if (a[y + 1]) ++cnt;
			}
			if (y + 2 <= n) {
				if (a[y + 2]) --cnt;
				a[y + 2] += f[y - x + 1];
				a[y + 2] = (a[y + 2] % m + m) % m;
				if (a[y + 2]) ++cnt;
			}
		}
		if (!cnt) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}