#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], l[N], r[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!l[a[i]]) l[a[i]] = i;
		r[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (l[i] != r[i]) t[l[i]] = r[i];
	}
	int ans = 0;
	for (int i = 1; i <= n;) {
		if (!t[i]) {
			++i;
			continue;
		}
		priority_queue<int> q;
		int u = i, v = t[i], c = 0;
		while (u <= v) {
			++c;
			for (; u <= v; ++u) {
				if (t[u]) q.push(t[u]);
			}
			v = q.top();
		}
		ans += v - i - c;
		i = v + 1;
	}
	cout << ans << '\n';
	return 0;
}