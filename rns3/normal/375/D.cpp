#include <bits/stdc++.h>
using namespace std;

#define N 101010

int n, p[N], m, x[N], k[N];
int c[N];

int ST[N], EN[N];

vector <int> v[N];

int id[N], rk[N];

int clk;
void dfs(int x, int fa) {
	clk ++;
	ST[x] = clk;
	id[clk] = x;
	rk[x] = clk;
	for (int i = 0, y; i < v[x].size(); i ++) {
		y = v[x][i];
		if (y == fa) continue;
		dfs(y, x);
	}
	EN[x] = clk;
}

int ans[N];

int L = 1, R = 0;
int aa[N], bb[N], cnt[N];

bool cmp(int i, int j) {
	return EN[x[i]] < EN[x[j]];
}

const int K = 400;

void add(int x, int val = 1) {
	if (cnt[x] > 0) {
		aa[cnt[x]] --;
		bb[(int)((cnt[x]-1)/K)] --;
	}
	cnt[x] += val;
	if (cnt[x] > 0) {
		aa[cnt[x]] ++;
		bb[(cnt[x]-1)/K] ++;
	}
}

int calc(int k) {
	int rlt = 0;
	while (k <= n) {
		if (k % K == 1) {
			rlt += bb[(k-1)/K];
			k += K;
		}
		else {
			rlt += aa[k];
			k ++;
		}
	}
	return rlt;
}

void go(int le, int ri) {
	while (L < le) add(c[id[L]], -1), L ++;
	while (L > le) L --, add(c[id[L]]);
	while (R > ri) add(c[id[R]], -1), R --;
	while (R < ri) R ++, add(c[id[R]]);
}

void solve(vector <int> &v, bool rv) {
	sort(v.begin(), v.end(), cmp);
	if (rv) reverse(v.begin(), v.end());
	for (int i = 0, y; i < v.size(); i ++) {
		y = x[v[i]];
		go(ST[y], EN[y]);
        ans[v[i]] = calc(k[v[i]]);
	}
}

vector <int> u[N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	for (int i = 1, x, y; i < n; i ++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &x[i], &k[i]);
		int type = (rk[x[i]] - 1) / K;
		u[type].push_back(i);
	}
	bool rv = 0;
	for (int i = 0; i <= (N - 1) / K; i ++) if (!u[i].empty()) solve(u[i], rv), rv = !rv;
	for (int i = 1; i <= m; i ++) printf("%d\n", ans[i]);


	return 0;
}