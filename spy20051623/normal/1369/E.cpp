#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], x[N], y[N], vis[N];
vector<int> g[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	queue<int> q;
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
		++b[x[i]];
		++b[y[i]];
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= b[i]) {
			for (int j: g[i]) {
				if (!vis[j]) {
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
	stack<int> s;
	for (int i = 0; i < m; ++i) {
		if (q.empty()) {
			cout << "DEAD\n";
			return 0;
		}
		int p = q.front();
		q.pop();
		s.push(p);
		--b[x[p]];
		--b[y[p]];
		if (b[x[p]] == a[x[p]]) {
			for (int j: g[x[p]]) {
				if (!vis[j]) {
					q.push(j);
					vis[j] = 1;
				}
			}
		}
		if (b[y[p]] == a[y[p]]) {
			for (int j: g[y[p]]) {
				if (!vis[j]) {
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
	cout << "ALIVE\n";
	while (!s.empty()) cout << s.top() << ' ', s.pop();
	return 0;
}