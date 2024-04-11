#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int a[N], f[N];
set<int> s;

int lg(int x) {
	int c = -1;
	while (x) {
		++c;
		x >>= 1;
	}
	return c;
}

void solve() {
	f[1] = 1;
	for (int i = 2; i < N; ++i) {
		f[i] = (f[i - 1] + f[i - 2] + 1) % mod;
	}
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert(a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (p <= 30 && a[i] >= 1 << p) continue;
		int x = a[i];
		bool ok = true;
		while (x) {
			if (x != a[i] && s.find(x) != s.end()) {
				ok = false;
				break;
			}
			if (x & 1) x /= 2;
			else if (x % 4 == 0) x /= 4;
			else break;
		}
		if (!ok) continue;
		int d = p - lg(a[i]);
		ans = (ans + f[d]) % mod;
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}