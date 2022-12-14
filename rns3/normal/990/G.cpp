#include <bits/stdc++.h>

using namespace std;



#define N 202020



vector <int> yak[N];



void prep() {

	for (int i = 1; i < N; i ++) {

		for (int j = i; j < N; j += i) yak[j].push_back(i);

	}

}



int n, val[N];



vector <int> v[N];

int node[N], nodes, pa[N], son[N], del[N];

long long ans[N];



int bfs(int x) {

	nodes = 0;

	pa[node[++nodes]=x] = 0;

	for (int i = 1; i <= nodes; i ++) {

		x = node[i];

		son[x] = 1;

		for (int j = 0; j < v[x].size(); j ++) {

			int y = v[x][j];

			if (y != pa[x] && !del[y]) pa[node[++nodes]=y] = x;

		}

	}

	for (int i = nodes; i >= 1; i --) {

		int x = node[i];

		if (son[x] * 2 >= nodes) return x;

		son[pa[x]] += son[x];

	}

	return 0;

}



int mval;

int go[N];

int tmp[N], tot[N];



int gp[N], now[N];



void dfs(int x, int y, int kick) {

	kick = __gcd(kick, val[x]);

	tmp[go[kick]] ++;

	for (int i = 0, z; i < v[x].size(); i ++) {

		z = v[x][i];

		if (z == y || del[z]) continue;

		dfs(z, x, kick);

	}

}



void DFS(int x, int y, int kick, int grp) {

	kick = __gcd(kick, val[x]);

	now[x] = kick;

	gp[x] = grp;

	for (int i = 0, z; i < v[x].size(); i ++) {

		z = v[x][i];

		if (z == y || del[z]) continue;

		DFS(z, x, kick, grp);

	}

}



int tik[202][202];



void calc(int rt) {

	mval = val[rt];

	int sz = yak[mval].size();

	for (int i = 0; i < sz; i ++) go[yak[mval][i]] = i;

	memset(tot, 0, sz * sizeof (int));

	tot[go[val[rt]]] = 1;

	for (int j = 0; j < sz; j ++) tik[go[val[rt]]][j] = __gcd(yak[mval][go[val[rt]]], yak[mval][j]), tik[j][go[val[rt]]] = tik[go[val[rt]]][j];

	ans[val[rt]] ++;

	for (int i = 0, x; i < v[rt].size(); i ++) {

		x = v[rt][i];

		if (del[x]) continue;

		memset(tmp, 0, sz * sizeof (int));

		dfs(x, rt, mval);

		for (int i = 0; i < sz; i ++) if (tmp[i]) for (int j = 0; j < sz; j ++) {

			ans[tik[i][j]] += 1ll * tmp[i] * tot[j];

		}

		for (int i = 0; i < sz; i ++) {

			if (!tot[i] && tmp[i]) {

				for (int j = 0; j < sz; j ++) tik[i][j] = __gcd(yak[mval][i], yak[mval][j]), tik[j][i] = tik[i][j];

			}

			tot[i] += tmp[i];

		}

	}

}



void brute_calc(int rt) {

	mval = val[rt];

	for (int i = 0, x; i < v[rt].size(); i ++) {

		x = v[rt][i];

		if (del[x]) continue;

		DFS(x, rt, mval, x);

	}

	ans[val[rt]] ++;

	gp[rt] = -1;

	now[rt] = val[rt];

	for (int i = 1; i <= nodes; i ++) for (int j = i + 1; j <= nodes; j ++) {

		if (gp[node[i]] != gp[node[j]]) ans[__gcd(now[node[i]], now[node[j]])] ++;

	}

}



void solve(int x) {

	int rt = bfs(x);

	del[rt] = 1;

	if (nodes <= 50) brute_calc(rt);

	else calc(rt);

	for (int i = 0; i < v[rt].size(); i ++) if (!del[v[rt][i]]) solve(v[rt][i]);

}



int main() {

//	freopen("1.in", "r", stdin);

//	freopen("w.out", "w", stdout);

	prep();

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &val[i]);

	for (int i = 1, x, y; i < n; i ++) {

		scanf("%d %d", &x, &y);

		v[x].push_back(y);

		v[y].push_back(x);

	}

	solve(1);

	for (int i = 1; i < N; i ++) if (ans[i]) {

		printf("%d %I64d\n", i, ans[i]);

	}



	return 0;

}