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

const int N = (int) 1e6 + 6, mod = (int) 0;
int n, m, k, tot, cur, mark[N];
vector<int> adj[N], res[N];
void add(int v) {
	int lim = (2 * n + k - 1) / k;
	while (res[cur].size() >= lim) ++cur;
	res[cur].push_back(v);
}
void dfs(int v, int p = -1) {
	mark[v] = 1;
	add(v);
	int cnt = 0;
	for (int u : adj[v]) if (u != p && !mark[u]) {
		dfs(u, v);
		add(v);
		++cnt;
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int j = 0; j < m; ++j) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	while (cur < k) {
		if (res[cur].size() == 0) res[cur].push_back(0);
		++cur;
	}
	for (int j = 0; j < k; ++j) {
		printf("%d ", (int) res[j].size());
		for (int x : res[j])
			printf("%d ", 1 + x);
		printf("\n");
	}
}