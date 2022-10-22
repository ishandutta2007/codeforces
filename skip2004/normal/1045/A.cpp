#include<bits/stdc++.h>
const int N = 10010;
const int inf = 1e6;
using std::cin;
using std::cout;
std::unordered_map<int, int> edge[N];
int n, m, tot;
namespace gf {
	const int maxn = 1000100;
	struct T {
		int to, nxt, v;
	} way[maxn << 1];
	int h[maxn], H[maxn], num = 1;
	inline void link(int x, int y, int v) {
		way[++num] = {y, h[x], v}, h[x] = num;
		way[++num] = {x, h[y], 0}, h[y] = num;
	}
	int dis[maxn];
	inline bool bfs(int s, int t) {
		std::queue<int> q;
		for(int i = s;i <= t;++i) {
			dis[i] = inf;
		}
		q.push(t), dis[t] = 0;
		for(;q.size();) {
			int x = q.front(); q.pop();
			for(int i = h[x];i;i = way[i].nxt) if(way[i ^ 1].v && dis[way[i].to] == inf) {
				dis[way[i].to] = dis[x] + 1;
				q.push(way[i].to);
			}
		}
		return dis[s] != inf;
	}
	inline int dfs(int s, int t, int lim) {
		if(s == t || !lim) return lim;
		int ans = 0, mn;
		for(int & i = H[s];i;i = way[i].nxt) if(dis[way[i].to] < dis[s] && (mn = dfs(way[i].to, t, std::min(lim, way[i].v)))) {
			way[i].v -= mn, way[i ^ 1].v += mn;
			ans += mn, lim -= mn;
			if(!lim) break;
		}
		return ans;
	}
	inline int dinic(int s, int t) {
		int ans = 0;
		for(;bfs(s, t);) {
			for(int i = s;i <= t;++i) H[i] = h[i];
			ans += dfs(s, t, 1e9);
		}
		for(int i = 2;i <= num;++i) {
			if(way[i ^ 1].to <= n + m) edge[way[i ^ 1].to][way[i].to] = way[i].v;
		}
		return ans;
	}
}
int opt[N], l[N], r[N], k[N];
int a[N], b[N], c[N];
std::vector<int> v[N];
int st[20][N];
int bel[N];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m;
	tot = n + m;
	for(int i = 1;i <= m;++i) {
		st[0][i] = i + n;
	}
	for(int i = 1;i < 20;++i) {
		for(int j = 1;j + (1 << i) - 1 <= m;++j) {
			st[i][j] = ++ tot;
			gf::link(st[i][j], st[i - 1][j], inf);
			gf::link(st[i][j], st[i - 1][j + (1 << i - 1)], inf);
		}
	}
	for(int i = 1;i <= n;++i) {
		cin >> opt[i];
		if(opt[i] == 0) {
			gf::link(0, i, 1);
			cin >> k[i];
			for(int j = 0, x;j < k[i];++j) {
				cin >> x;
				gf::link(i, x + n, 1);
				v[i].push_back(x);
			}
		} else if(opt[i] == 1) {
			cin >> l[i] >> r[i];
			const int lg = std::__lg(r[i] - l[i] + 1);
			gf::link(0, i, 1);
			gf::link(i, st[lg][l[i]], 1);
			gf::link(i, st[lg][r[i] - (1 << lg) + 1], 1);
		} else {
			cin >> a[i] >> b[i] >> c[i];
			gf::link(0, i, 2);
			gf::link(i, a[i] + n, 1);
			gf::link(i, b[i] + n, 1);
			gf::link(i, c[i] + n, 1);
		}
	}
	int t = ++ tot;
	for(int i = 1;i <= m;++i) {
		gf::link(i + n, t, 1);
	}
	int res = gf::dinic(0, t);
	struct seq {
		int id, l, r;
		inline bool operator < (const seq & b) const {
			return r > b.r;
		}
	};
	std::vector<seq> vec;
	std::vector<int> to;
	for(int i = 1;i <= n;++i) if(edge[i][0]) {
		if(opt[i] == 0) {
			for(int x : v[i]) if(edge[i][x + n] == 0) {
				bel[x] = i;
				break;
			}
		} else if(opt[i] == 2) {
			if(edge[i][a[i] + n] == 0) bel[a[i]] = i;
			if(edge[i][b[i] + n] == 0) bel[b[i]] = i;
			if(edge[i][c[i] + n] == 0) bel[c[i]] = i;
		} else {
			vec.push_back({i, l[i], r[i]});
		}
	}
	for(int i = 1;i <= m;++i) if(edge[n + i][t] == 0 && !bel[i]) {
		to.push_back(i);
	}
	sort(vec.begin(), vec.end(), [](const seq & x, const seq & y) {
		return x.l < y.l;
	});
	std::priority_queue<seq> q;
	for(int i : to) {
		static int id = 0;
		for(;id < vec.size() && vec[id].l <= i;++id) {
			q.push(vec[id]);
		}
		bel[i] = q.top().id;
		q.pop();
	}
	for(int i = 1;i <= n;++i) if(edge[i][0]) {
		if(opt[i] == 2) {
			if((bel[a[i]] == i) + (bel[b[i]] == i) + (bel[c[i]] == i) == 1) {
				if(bel[a[i]] != i) { bel[a[i]] = i; continue; }
				if(bel[b[i]] != i) { bel[b[i]] = i; continue; }
				if(bel[c[i]] != i) { bel[c[i]] = i; continue; }
			}
		}
	}
	cout << res << '\n';
	for(int i = 1;i <= m;++i) if(bel[i]) {
		cout << bel[i] << ' ' << i << '\n';
	}
}