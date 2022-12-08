#include <bits/stdc++.h>

using namespace std;

int d[1000005];
int n, c;

int lowbit(int x) { return x & -x; }

void upd(int x, int k) { for (; x <= c; x += lowbit(x)) d[x] += k; }

int qry(int x) {
	int s = 0;
	for (; x > 0; x -= lowbit(x)) s += d[x];
	return s;
}

void solve() {
	cin >> n >> c;
	fill(d, d + c + 5, 0);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	n = a.size();
	if (a[0] != 1) {
		cout << "NO\n";
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (qry(a[i]) < i - 1) {
			cout << "NO\n";
			return;
		}
		for (int j = 0; j < n; ++j) {
			if (1ll * a[i] * a[j] <= c) {
				upd(a[i] * a[j], 1);
				if (1ll * a[i] * a[j] + a[i] <= c) upd(a[i] * a[j] + a[i], -1);
			} else break;
		}
	}
	cout << "YES\n";
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