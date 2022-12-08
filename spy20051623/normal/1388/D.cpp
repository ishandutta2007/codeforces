#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
long long a[N], b[N], in[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i], b[i] == -1 ? 0 : ++in[b[i]];
	vector<int> v;
	stack<int> s;
	queue<int> q;
	for (int i = 1; i <= n; ++i) if (!in[i]) q.push(i);
	long long ans = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		ans += a[p];
		if (b[p] != -1) {
			--in[b[p]];
			if (!in[b[p]]) q.push(b[p]);
			if (a[p] >= 0) {
				a[b[p]] += a[p];
				v.push_back(p);
			} else {
				s.push(p);
			}
		} else v.push_back(p);
	}
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	cout << ans << '\n';
	for (int i: v) cout << i << ' ';
	return 0;
}