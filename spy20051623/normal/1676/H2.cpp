#include <bits/stdc++.h>

using namespace std;

int n;
int d[200005];

int lowbit(int x) { return x & -x; }

void upd(int x) { for (; x <= n; x += lowbit(x)) ++d[x]; }

int qry(int x) {
	int s = 0;
	for (; x; x -= lowbit(x)) s += d[x];
	return s;
}

void solve() {
//	int n;
	cin >> n;
	fill(d, d + n + 5, 0);
	vector<int> a(n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ans += i - qry(a[i] - 1);
		upd(a[i]);
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}