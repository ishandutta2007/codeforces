#include <bits/stdc++.h>
using namespace std;

const int N = 211, M = 1811;
const int Inf = 0x3f3f3f3f;

int m = 2;
int fe[N], ne[M];
int eu[M], ev[M], f[M];
void add(int u, int v, int w) {
	eu[m] = u; ev[m] = v; f[m] = w;
	ne[m] = fe[u]; fe[u] = m ++;
	eu[m] = v; ev[m] = u; f[m] = 0;
	ne[m] = fe[v]; fe[v] = m ++;
}

int T, arc[N], lev[N];
int extend(int x, int flow) {
	if (x == T) return flow;
	int re = 0;
	for (int &e = arc[x]; e; e = ne[e])
		if (f[e] && lev[ev[e]] == lev[x] + 1) { // sgn(f[e]) &&
			int t = extend(ev[e], min(flow - re, f[e]));
			if (t) { // sgn(t)
				f[e] -= t;
				f[e ^ 1] += t;
				if ((re += t) == flow) break; // !sgn((re+=t), flow)
			}
		}
	if (!re) lev[x] = 0; // !sgn(re)
	return re;
}
int q[N], *qb, *qe;
int dinic(int S, int T) {
	::T = T;
	int re = 0;
	for (;;) {
		fill(lev, lev + T + 1, 0);
		copy(fe, fe + T + 1, arc);
		for (qb = qe = q, lev[*qe++ = S] = 1; qb != qe;) {
			int x = *qb++;
			if (lev[T]) break;
			for (int e = fe[x]; e; e = ne[e])
				if (f[e] && !lev[ev[e]]) // sgn(f[e]) &&
					lev[*qe++ = ev[e]] = lev[x] + 1;
		}
		if (!lev[T]) break;
		re += extend(S, Inf);
	}
	return re;
}

int a[N], b[N];
int ans[N][N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	for(int i = 0; i < m; i ++) {
		int u, v; cin >> u >> v;
		add(u, v + n, Inf);
		add(v, u + n, Inf);
	}
	for(int i = 1; i <= n; i ++)
		add(i, i + n, Inf);
	for(int i = 1; i <= n; i ++) {
		add(0, i, a[i]);
		add(i + n, 2 * n + 1, b[i]);
	}
	int sa = accumulate(a + 1, a + n + 1, 0);
	int sb = accumulate(b + 1, b + n + 1, 0);
	if(dinic(0, 2 * n + 1) == sa && sa == sb) {
		cout << "YES\n";
		for(int i = 2; i <= 2 * (2 * m + n); i += 2)
			ans[eu[i]][ev[i] - n] = f[i ^ 1];
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++)
				cout << ans[i][j] << ' ';
			cout << '\n';
		}
	} else cout << "NO\n";
	return 0;
}