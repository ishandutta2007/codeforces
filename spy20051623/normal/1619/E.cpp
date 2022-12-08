#include <bits/stdc++.h>

using namespace std;

int a[200005];
int c[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; ++i) ++c[a[i]];
	stack<int> s;
	long long sum = 0;
	bool ok = true;
	for (int i = 0; i <= n; ++i) {
		if (i && !c[i - 1] && s.empty()) ok = false;
		if (!ok) {
			cout << "-1 ";
			continue;
		}
		if (i && !c[i - 1]) {
			sum += i - 1 - s.top();
			s.pop();
		}
		cout << sum + c[i] << ' ';
		for (int j = 0; j < c[i] - 1; ++j) s.push(i);
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) --c[a[i]];
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