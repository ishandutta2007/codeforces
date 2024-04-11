#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pnt;

#define N 101010

struct Fenwick {
	int a[N], n;
	void init(int sz) {
		n = sz;
		memset(a, 0, (n + 1) * sizeof (a[0]));
	}
	void add(int j) {
		for (int k = j; k <= n; k += k & -k) a[k] ++;
	}
	int calc(int j) {
		int rlt = 0;
		for (int k = j; k; k -= k & -k) rlt += a[k];
		return rlt;
	}
} Fen;

int id[N], tmp[N];

int *cmp_pos;
bool cmp(int i, int j) {
	return cmp_pos[i] < cmp_pos[j];
}

struct Problem {
	int n, m;
	pnt p[N], q[N];
	void add_pnt(pnt a) {p[++n] = a;}
	void add_query(pnt a) {q[++m] = a;}
	long long solve() {
		sort(p + 1, p + n + 1);
		sort(q + 1, q + m + 1);
		int mx = 0;
		for (int i = 1; i <= n; i ++) mx = max(mx, p[i].second);
		Fen.init(mx);
		long long rlt = 0;
		for (int e = 1, f = 1; f <= m; f ++) {
			while (e <= n && p[e].first <= q[f].first) Fen.add(p[e++].second);
			rlt += Fen.calc(min(q[f].second, mx));
		}
		return rlt;
	}
} P;


vector <int> v[N], w[N];

int n, X, Y;

bool del[N];

vector <pnt> S, TMP;

void DFS(int x, int fa, int len, int wei) {
	if (len > X || wei > Y) return;
	TMP.push_back(make_pair(len, wei));
	for (int i = 0, y, z; i < v[x].size(); i ++) {
		y = v[x][i], z = w[x][i];
		if (y == fa || del[y]) continue;
		DFS(y, x, len + 1, wei + z);
	}
}

long long query(vector <pnt> &v) {
	P.n = P.m = 0;
	for (int i = 0; i < v.size(); i ++) P.add_pnt(make_pair(v[i].second, v[i].first + 1)), P.add_query(make_pair(Y - v[i].second, 1 + X - v[i].first));
	return P.solve();
}

long long ans;

void calc(int x) {
	S.clear();
	for (int i = 0, y, z; i < v[x].size(); i ++) {
		y = v[x][i], z = w[x][i];
		if (del[y]) continue;
		TMP.clear();
		DFS(y, x, 1, z);
		ans -= query(TMP);
		for (int j = 0; j < TMP.size(); j ++) S.push_back(TMP[j]);
	}
	ans += query(S);
	ans += S.size() * 2;
}

int nodes, node[N], ms[N], sz[N];

void dfs(int x, int fa = 0) {
	node[++nodes] = x;
	ms[x] = 0, sz[x] = 1;
	for (int i = 0, y; i < v[x].size(); i ++) {
		y = v[x][i];
		if (y == fa || del[y]) continue;
		dfs(y, x);
		sz[x] += sz[y];
		ms[x] = max(ms[x], sz[y]);
	}
}

void solve(int x) {
	nodes = 0;
	dfs(x);
	int rt = 0;
	for (int i = 1, tmp; i <= nodes; i ++) {
		if (max(ms[node[i]], nodes - sz[node[i]]) <= nodes / 2) {
			rt = node[i];
			break;
		}
	}
	del[rt] = 1;
	calc(rt);
	for (int i = 0, y; i < v[rt].size(); i ++) {
		y = v[rt][i];
		if (del[y]) continue;
		solve(y);
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d", &n, &X, &Y);
	for (int i = 2, j, z; i <= n; i ++) {
		scanf("%d %d", &j, &z);
		v[i].push_back(j);
		v[j].push_back(i);
		w[i].push_back(z);
		w[j].push_back(z);
	}
	ans = 0;
	solve(1);
	printf("%I64d\n", ans / 2);

	return 0;
}