#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int rep[MAXN], ma[MAXN];

void init() {
	fill(rep, rep + MAXN, -1);
	iota(ma, ma + MAXN, 0);
}

int find(int u) {
	return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
	u = find(u), v = find(v);
	if(u == v)
		return;
	rep[v] = u;
	ma[u] = max(ma[u], ma[v]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	int n, m;
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		join(u, v);
	}
	set<int> cc;
	int ans = 0, cur = 1;
	for(int i = 1; i <= n; i++) {
		int u = find(i);
		cc.insert(u);
		cur = max(cur, ma[u]);
		if(cur == i) {
			ans += cc.size() - 1;
			cc.clear();
		}
	}
	cout << ans << '\n';
}