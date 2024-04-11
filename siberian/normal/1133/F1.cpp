#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MAXN = 2*1e5 + 10;
vector <int> g[MAXN];
int n, m;

void read() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
vector <pair <int, int> > ans;
bool used[MAXN];
void run() {
	int v = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		if (mx < g[i].size()) {
			mx = g[i].size();
			v = i;
		}
	}

	deque<int> q;
	q.push_back(v);
	used[v] = true;
	while (!q.empty()) {
		v = q[0];
		q.pop_front();
		for (auto i : g[v]) {
			if (!used[i]) {
				used[i] = true;
				ans.push_back({i + 1, v + 1});
				q.push_back(i);
			}
		}
	}
}

void write() {
	for (auto i : ans)
		cout << i.first << " " << i.second << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}