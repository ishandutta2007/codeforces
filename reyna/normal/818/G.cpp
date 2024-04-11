// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
#define prev wow
const int N = (int) 4e7 + 7, M = 1e5 + 5, mod = (int) 0;
int cnt = 0;
int en, q[N], mark[M], head[M], prev[N], cap[N], to[N], cost[N], d[M], par[M];
int spfa(int src, int snk) {
	for (int j = 0; j < cnt; ++j) d[j] = 1e9, par[j] = -1, mark[j] = 0;
	d[src] = 0;
	int h = 0, t = 0;
	q[t++] = src;
	mark[src] = 1;
	while (h != t) {
		int v = q[h++];
		mark[v] = 0;
		for (int e = head[v]; ~e; e = prev[e]) if (cap[e]) {
			int u = to[e], w = cost[e];
			if (d[u] > d[v] + w) {
				d[u] = d[v] + w;
				par[u] = e;
				if (!mark[u]) {
					mark[u] = 1;
					q[t++] = u;	
				}
			}
		}
	}
	if (d[snk] > 0) return 0;
	int cur = snk;
	while (par[cur] != -1) {
		int e = par[cur];
		cap[e]--;
		cap[e ^ 1]++;
		cur = to[e ^ 1];
	}
	return d[snk];
}
int mcmf(int src, int snk) {
	int res = 0;
	for (int j = 0; j < 4; ++j) {
		res += min(0, spfa(src, snk));
	}
	return res;
}
void add_edge(int u, int v, int cs, int uv = 1) {
	cap[en] = uv, cost[en] = cs, to[en] = v, prev[en] = head[u], head[u] = en++;	
	cap[en] = 0, cost[en] = -cs, to[en] = u, prev[en] = head[v], head[v] = en++;	
}
int a[M], h[7], c[M];
int main() {
	memset(head, -1, sizeof head);
	int n;
	cin >> n;
	cnt = 2 * n + 2;
	int src = n * 2, snk = n * 2 + 1;
	for (int j = 0; j < n; ++j) cin >> a[j];
	/*
	for (int x = 0; x < n; ++x)
		for (int y = x + 1; y < n; ++y)
			if (abs(a[x] - a[y]) == 1)
				add_edge(x << 1 | 1, y << 1 | 0, 0);
				*/
	for (int j = 0; j < M; ++j) c[j] = snk;
	for (int j = 0; j < 7; ++j) h[j] = snk;
	for (int x = n - 1; x >= 0; --x) {
		{
		int to = h[a[x] % 7];
		int cur = cnt++;
		h[a[x] % 7] = cur;
		add_edge(cur, to, 0, (int) 1e9);
		add_edge(cur, x << 1 | 0, 0, (int) 1);
		add_edge(x << 1 | 1, to, 0, (int) 1);
		}
		{
		int to = c[a[x]];
		int cur = cnt++;
		c[a[x]] = cur;
		add_edge(cur, to, 0, (int) 1e9);
		add_edge(cur, x << 1 | 0, 0, (int) 1);
		add_edge(x << 1 | 1, c[a[x] + 1], 0, (int) 1);
		add_edge(x << 1 | 1, c[a[x] - 1], 0, (int) 1);
		}
	}
	for (int x = 0; x < n; ++x) {
		add_edge(x << 1 | 0, x << 1 | 1, -1);
		add_edge(src, x << 1 | 0, 0);
		add_edge(x << 1 | 1, snk, 0);
	}
	cout << -mcmf(src, snk) << endl;	
			
}