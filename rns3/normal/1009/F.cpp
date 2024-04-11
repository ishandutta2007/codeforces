#include <bits/stdc++.h>

using namespace std;



#define N 1010101



const int K = 1000;



vector <int> v[N];



int n, dp[N];



int le[N], ri[N];



int a[N];



int clk;

void dfs(int x, int y, int dpt) {

	dp[x] = dpt;

	clk ++;

	le[x] = clk;

	a[clk] = dpt;

	for (int i = 0, z; i < v[x].size(); i ++) {

		z = v[x][i];

		if (z == y) continue;

		dfs(z, x, dpt + 1);

	}

	ri[x] = clk;

}



int xx[K+1], yy[K+1][K+1];



int L, R, cnt[N];



void add(int a, int d) {

	if (cnt[a] < K) {

		xx[cnt[a]] --;

		yy[cnt[a]][a/K] --;

	}

	cnt[a] += d;

	if (cnt[a] < K) {

		xx[cnt[a]] ++;

		yy[cnt[a]][a/K] ++;

	}

}



int q[N], e;



int answer() {

	int rlt = 0, ff = -1;

	for (int i = 1; i <= e; i ++) if (cnt[q[i]] >= K) {

		if (cnt[q[i]] > rlt) rlt = cnt[q[i]], ff = q[i];

	}

	if (rlt >= K) return ff;

	for (int i = K - 1; i >= rlt; i --) if (xx[i]) {

		for (int j = 0; j <= n / K; j ++) if (yy[i][j]) {

			for (int tt = j * K; tt < (j + 1) * K; tt ++) {

				if (tt > n) continue;

				if (cnt[tt] == i) {

					if (i > rlt) return tt;

					else if (tt < ff) return tt;

				}

			}

		}

	}

	assert(0);

}



void go(int le, int ri) {

	while (L > le) add(a[--L], 1);

	while (R < ri) add(a[++R], 1);

	while (L < le) add(a[L++], -1);

	while (R > ri) add(a[R--], -1);

}



bool cmp(int i, int j) {

	return ri[i] < ri[j];

}



int ans[N];



void solve(vector <int> &v, bool rv) {

	if (rv) sort(v.begin(), v.end(), cmp);

	else sort(v.rbegin(), v.rend(), cmp);

	for (int ii = 0, i; ii < v.size(); ii ++) {

		i = v[ii];

		go(le[i], ri[i]);

		ans[i] = answer();

	}

}



vector <int> u[N];



int th[N];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	for (int i = 1, x, y; i < n; i ++) {

		scanf("%d %d", &x, &y);

		v[x].push_back(y);

		v[y].push_back(x);

	}

	dfs(1, 0, 1);

	for (int i = 1; i <= n; i ++) u[le[i]/K].push_back(i);

	for (int i = 1; i <= n; i ++) th[dp[i]] ++;

	for (int i = 1; i <= n; i ++) if (th[i] >= K) q[++e] = i;

	bool rv = 0;

	L = 1, R = 0;

	for (int i = 0; i < N; i ++) if (!u[i].empty()) {

		solve(u[i], rv);

		rv = !rv;

	}

	for (int i = 1; i <= n; i ++) printf("%d\n", ans[i] - dp[i]);



	return 0;

}