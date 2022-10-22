#include<bits/stdc++.h>
const int N = 400100;
const int M = 1001000;
struct T {
	int to, nxt;
} way[M << 1];
int n, m, s, t;
int h[N], num;
inline void link(int x,int y) {
	way[++num] = {y, h[x]}, h[x] = num;
	way[++num] = {x, h[y]}, h[y] = num;
}
int x[M], y[M], dir[M];
int fa[N], fa_edge[N], son[N], dep[N];
std::vector<int> edge[N];
inline void dfs0(int x, int fa, int fa_edge) {
	:: fa[x] = fa, ::fa_edge[x] = fa_edge, dep[x] = dep[fa] + 1;
	for(int i = h[x];i;i = way[i].nxt) if(i ^ fa_edge ^ 1) {
		if(!dep[way[i].to]) {
			son[x] = way[i].to;
			dfs0(way[i].to, x, i);
		} else if(dep[way[i].to] < dep[x]) {
			edge[son[way[i].to]].push_back(i);
		}
	}
}
int main() {
	using std::cin;
	using std::cout;
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	int T;
	cin >> T;
	for(;T--;) {
		cin >> n >> m >> s >> t;
		num = 1;
		for(int i = 1;i <= n;++i) {
			h[i] = fa[i] = fa_edge[i] = son[i] = dep[i] = 0;
			edge[i].clear();
		}
		for(int i = 1;i <= m;++i) {
			cin >> x[i] >> y[i];
			link(x[i], y[i]);
			dir[i] = -1;
		}
		dfs0(s, 0, 0);
		typedef std::pair<int, int> pr;
		std::queue<pr> q; q.emplace(t, 0);
		for(;!q.empty();) {
			pr x = q.front(); q.pop();
			int u = x.first, d = x.second;
			for(;u != s && dir[fa_edge[u] >> 1] == -1;) {
				dir[fa_edge[u] >> 1] = d;
				for(int i : edge[u]) {
					dir[i >> 1] = d;
					q.emplace(way[i ^ 1].to, d ^ 1);
				}
				u = fa[u];
			}
		}
		int have = 1;
		for(int i = 1;i <= m;++i) if(dir[i] == -1) {
			have = 0; break;
		}
		if(!have) {
			cout << "No" << '\n';
		} else {
			cout << "Yes" << '\n';
			for(int i = 1;i <= m;++i) {
				if((dep[x[i]] > dep[y[i]]) ^ dir[i]) std::swap(x[i], y[i]);
				cout << x[i] << ' ' << y[i] << '\n';
			}
		}
	}
}