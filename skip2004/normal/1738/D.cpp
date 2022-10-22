#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 100005;
std::vector<int> go[N];
int a[N], b[N], p, n;
inline void dfs0(int x) {
	if(1 <= x && x <= n) {
		a[++p] = x;
	}
	sort(go[x].begin(), go[x].end(), [](int a, int b) { return go[a].size() < go[b].size(); });
	for(int u : go[x]) dfs0(u);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int t; cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> n;
		int l = 0, r = n;
		for(int i = 1;i <= n;++i) {
			cin >> b[i];
			auto o = std::minmax(i, b[i]);
			l = std::max(l, o.first);
			go[b[i]].push_back(i);
		}
		p = 0;
		dfs0(0); dfs0(n + 1);
		for(int i = 0;i <= n + 1;++i) go[i].clear();
		cout << l << '\n';
		for(int i = 1;i <= n;++i) {
			cout << a[i] << " \n"[i == n];
		}
	}
}