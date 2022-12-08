#include <bits/stdc++.h>

using namespace std;

int n, d[100005];

int lowbit(int x) { return x & -x; }

void upd(int x, int k) { for (; x <= n; x += lowbit(x)) d[x] += k; }

int qry(int x) {
	int r = 0;
	for (; x > 0; x -= lowbit(x)) r += d[x];
	return r;
}

void solve() {
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	string t;
	cin >> t;
	t = ' ' + t;
	fill(d, d + n + 5, 0);
	queue<int> q[26];
	for (int i = 1; i <= n; ++i) {
		upd(i, 1);
		q[s[i] - 'a'].push(i);
	}
	long long ans = 1e18, cur = 0;
	for (int i = 1; i <= n; ++i) {
		int p = 1e9;
		for (int j = 0; j < t[i] - 'a'; ++j) {
			if (!q[j].empty()) p = min(p, q[j].front());
		}
		if (p != 1e9) ans = min(ans, cur + qry(p - 1));
		if (q[t[i] - 'a'].empty()) break;
		cur += qry(q[t[i] - 'a'].front() - 1);
		upd(q[t[i] - 'a'].front(), -1);
		q[t[i] - 'a'].pop();
	}
	if (ans == 1e18) ans = -1;
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}