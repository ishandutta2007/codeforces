#include <bits/stdc++.h>
using namespace std;

#define N 707

int dp[N], n, a, b, mxdp, son[N], root[N];
vector <int> v[N], w[N];
bool vis[N];

struct bigint {
	int l, num[30];

	bigint (int m = 0) {
		memset(num, 0, sizeof num);
		l = 1;
		num[1] = m;
	}

	bigint operator * (const bigint &b) {
		bigint c;
		for (int i = 1; i <= l; i ++) {
			for (int j = 1; j <= b.l; j ++) {
				c.num[i+j-1] += num[i] * b.num[j];
			}
		}
		c.l = l + b.l;
		for (int i = 1; i < c.l; i ++) {
			c.num[i+1] += c.num[i] / 10000;
			c.num[i] %= 10000;
		}
		if (!c.num[c.l]) c.l --;
		return c;
	}

	bool operator < (const bigint &b) {
		if (l < b.l) return 1;
		else if (l > b.l) return 0;
		for (int i = l; i >= 1; i --) {
			if (num[i] < b.num[i]) return 1;
			else if (num[i] > b.num[i]) return 0;
		}
		return 0;
	}

	void operator = (const bigint &b) {
		l = b.l;
		for (int i = 1; i <= l; i ++) num[i] = b.num[i];
	}

	void print() {
		printf("%d", num[l]);
		for (int i = l - 1; i >= 1; i --) printf("%04d", num[i]);
		puts("");
	}
};

bigint max(bigint a, bigint b) {return a < b ? b : a;}

bigint f[N][N], F[N], g[N], one = bigint(1);

pair <int, int> edge[N];

void dfs(int x, int deep) {
	dp[x] = deep;
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		if (vis[v[x][i]]) continue;
		root[v[x][i]] = x;
		dfs(v[x][i], deep + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) v[i].clear();
	for (int i = 1; i < n; i ++) {
		scanf("%d %d", &a, &b);
		edge[i].first = a, edge[i].second = b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i ++) v[i].clear();
	for (int i = 1; i < n; i ++) {
		a = edge[i].first, b = edge[i].second;
		if (root[b] == a) v[a].push_back(b);
		else v[b].push_back(a);
	}
	for (int i = 1; i <= n; i ++) w[dp[i]].push_back(i), mxdp = max(mxdp, dp[i]);
	for (int i = 0; i < w[mxdp].size(); i ++) son[w[mxdp][i]] = 1;
	for (int k = mxdp - 1; k >= 0; k --) {
		for (int i = 0; i < w[k].size(); i ++) {
			int x = w[k][i];
			son[x] = 1;
			for (int j = 0; j < v[x].size(); j ++) son[x] += son[v[x][j]];
		}
	}

	for (int k = mxdp; k >= 0; k --) {
		for (int i = 0; i < w[k].size(); i ++) {
			int x = w[k][i];
			if (!v[x].size()) {f[x][1] = one;  F[x] = one; continue;}
			int pnt = 1;
			g[1] = one;
			for (int j = 0; j < v[x].size(); j ++) {
				int y = v[x][j];
                for (int s = 1; s <= pnt; s ++) f[x][s] = g[s] * F[y];
				for (int s = 1; s <= pnt; s ++) {
					for (int t = 1; t <= son[y]; t ++) {
						f[x][s+t] = max(f[x][s+t], g[s] * f[y][t]);
					}
				}
				pnt += son[y];
				for (int s = 1; s <= pnt; s ++) g[s] = f[x][s];
			}
			for (int j = 1; j <= pnt; j ++) F[x] = max(F[x], f[x][j] * bigint(j));
		}
	}
	F[1].print();
	return 0;
}