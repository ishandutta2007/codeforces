#include <bits/stdc++.h>
using namespace std;

const int N = 100005, inf = 0x3f3f3f3f;
int n, m, cost[2], x[N], y[N], deg[2 * N], cs[2 * N];
char def;
vector<int> vx, vy;

const int V = 2 * N, E = 2 * (N + 3 * N);
int SS, TT, S, T, all, tot = 1, nxt[E], fst[V], to[E], f[E], cur[V], d[V];

void addedge(int u, int v, int w) {
	if (!w) return;
	nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v; f[tot] = w;
	nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u; f[tot] = 0;
}
void addedge(int u, int v, int l, int r) {
	if (l > r) { cout << "-1\n"; exit(0); }
	addedge(u, v, r - l);
	addedge(S, v, l);
	addedge(u, T, l);
	all += l;
}
bool bfs(int SS, int TT) {
	static int q[V];
	int st = 0, ed = 0;
	q[ed++] = SS;
	for (int i = 1; i <= T; i++) d[i] = -1, cur[i] = fst[i];
	d[SS] = 0;
	while (st < ed) {
		int u = q[st++];
		for (int i = fst[u]; i; i = nxt[i])
			if (f[i] && d[to[i]] == -1) {
				d[to[i]] = d[u] + 1;
				if (to[i] == TT) return true;
				q[ed++] = to[i];
			}
	}
	return false;
}
int aug(int TT, int u, int flow) {
	if (u == TT || !flow) return flow;
	int used = 0;
	for (int &i = cur[u], w; i; i = nxt[i])
		if (d[to[i]] == d[u] + 1 && (w = aug(TT, to[i], min(f[i], flow - used)))) {
			f[i] -= w, f[i ^ 1] += w;
			if ((used += w) == flow) break;
		}
	if (!used) d[u] = -1;
	return used;
}
int dinic(int SS, int TT) {
	int ans = 0;
	while (bfs(SS, TT)) ans += aug(TT, SS, inf);
	return ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> cost[0] >> cost[1];
	if (cost[0] > cost[1]) swap(cost[0], cost[1]), def = 'b';
	else def = 'r';
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i], vx.push_back(x[i]), vy.push_back(y[i]);
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	for (int i = 1; i <= n; ++i) {
		x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
		++deg[x[i]];
		y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin() + (int)vx.size() + 1;
		++deg[y[i]];
		addedge(x[i], y[i], 1);
	}
	for (int i = 1; i <= (int)vx.size() + (int)vy.size(); ++i) cs[i] = inf;
	SS = (int)vx.size() + (int)vy.size() + 1;
	TT = SS + 1;
	S = TT + 1;
	T = S + 1;
	for (int t, l, d; m--;) {
		cin >> t >> l >> d;
		if (t == 1) {
			int tmp = lower_bound(vx.begin(), vx.end(), l) - vx.begin();
			if (tmp == (int)vx.size() || vx[tmp] != l) continue;
			l = tmp + 1;
			cs[l] = min(cs[l], d);
		} else {
			int tmp = lower_bound(vy.begin(), vy.end(), l) - vy.begin();
			if (tmp == (int)vy.size() || vy[tmp] != l) continue;
			l = (int)vx.size() + tmp + 1;
			cs[l] = min(cs[l], d);
		}
	}
	for (int i = 1; i <= (int)vx.size(); ++i) addedge(SS, i, max(0, (deg[i] - cs[i] + 1) / 2), min(deg[i], (deg[i] + cs[i]) / 2));
	for (int i = (int)vx.size() + 1; i <= (int)vx.size() + (int)vy.size(); ++i) addedge(i, TT, max(0, (deg[i] - cs[i] + 1) / 2), min(deg[i], (deg[i] + cs[i]) / 2));
	addedge(TT, SS, inf);
	if (dinic(S, T) != all) return cout << "-1\n", 0;
	int ans = f[tot];
	f[tot] = f[tot - 1] = 0;
	ans -= dinic(TT, SS);
	cout << 1ll * n * cost[0] + 1ll * (cost[1] - cost[0]) * ans << '\n';
	for (int i = 1; i <= n; ++i) {
		char c[2] = {def, 'r' + 'b' - def};
		cout << c[f[2 * i + 1]];
	}
	cout << endl;
}