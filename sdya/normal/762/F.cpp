#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int P = 1000000007LL;

map < vector < int >, int > M;
int ids = 0;
vector < vector < int > > vbyid;

long long inv(long long a) {
	long long x1 = 1, b1 = a;
	long long x2 = 0, b2 = P;
	while (b2) {
		long long q = b1 / b2;
		b1 -= q * b2;
		x1 -= q * x2;
		swap(b1, b2);
		swap(x1, x2);
	}
	return ((x1 % P) + P) % P;
}

int getId(const vector < int > &a) {
	if (M.count(a)) {
		return M[a];
	}
	vbyid.push_back(a);
	return M[a] = ids++;
}

const int maxN = 1100;
const int maxM = 15;
vector < int > g[maxN];
vector < int > h[maxN], rh[maxN];
int n, m;

int c[maxN];

void read(int &n, vector < int > g[maxN]) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

int dfs(vector < int > h[maxN], int c[], int v, int p = -1) {
	vector < int > codes;
	for (int i = 0; i < h[v].size(); ++i) {
		if (h[v][i] != p) {
			rh[v].push_back(h[v][i]);
			codes.push_back(dfs(h, c, h[v][i], v));
		}
	}
	sort(codes.begin(), codes.end());
	return c[v] = getId(codes);
}

int getCode(vector < int > h[maxN], int root) {
	return dfs(h, c, root, -1);
}

long long d[maxN][maxM];
long long t[maxN];

int dp[2][1 << 11];

long long f[maxN], invf[maxN];

inline void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

void calculate(vector < int > &g, int v, int root) {
	int cnt = vbyid[c[root]].size();
	if (g.size() < cnt) {
		return ;
	}

	int x = 0, y = 1;
	for (int i = 0; i < (1 << cnt); ++i) {
		dp[x][i] = 0;
	}
	dp[x][0] = 1;

	long long coef = 1;
	vector < int > a = vbyid[c[root]];
	int l = 0;
	for (int i = 1; i <= a.size(); ++i) {
		if (i == a.size() || a[i] > a[i - 1]) {
			int len = i - l;
			l = i;
			coef = (coef * invf[len]) % P;
		}
	}

	for (int t = 0; t < g.size(); ++t, swap(x, y)) {
		for (int i = 0; i < (1 << cnt); ++i) {
			dp[y][i] = 0;
		}

		for (int i = 0; i < (1 << cnt); ++i) {
			for (int j = 0; j < cnt; ++j) {
				if (i & (1 << j)) {
					continue;
				}

				add(dp[y][i ^ (1 << j)], ((long long)(dp[x][i]) * d[g[t]][rh[root][j]]) % P);
			}
			add(dp[y][i], dp[x][i]);
		}
	}
	d[v][root] = (long long)(dp[x][(1 << cnt) - 1]) * coef;
	d[v][root] %= P;
}

void calc(int v, int root, int p = -1) {
	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != p) {
			calc(g[v][i], root, v);
			children.push_back(g[v][i]);
		}
	}

	t[v] = 0;
	for (int i = 0; i < children.size(); ++i) {
		t[v] += t[children[i]];
	}

	for (int u = 0; u < m; ++u) {
		calculate(children, v, u);
	}
	t[v] += d[v][root];
	t[v] %= P;
}

long long solve(int root) {
	for (int i = 0; i < n; ++i) {
		t[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = 0;
		}
	}

	calc(0, root);
	return t[0];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (long long)(i) * f[i - 1];
		f[i] %= P;
	}
	for (int i = 0; i < maxN; ++i) {
		invf[i] = inv(f[i]);
	}

	read(n, g);
	read(m, h);

	set < int > used;
	long long res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			rh[j].clear();
		}
		int code = getCode(h, i);
		if (used.count(code)) {
			continue;
		}
		used.insert(code);

		res += solve(i);
		res %= P;
	}

	printf("%d\n", (int)(res));
	return 0;
}