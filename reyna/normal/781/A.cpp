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

const int N = (int) 1e6 + 5, mod = (int) 0;
int res[N];
vector<int> adj[N];
void dfs(int v, int p = -1, int pcol = -1) {
	int z = 0;
	while (z == pcol || z == res[v]) z++;
	for (int u : adj[v]) if (u != p) {
		while (z == pcol || z == res[v]) z++;
		res[u] = z++;
		dfs(u, v, res[v]);
	}
}
int main() {
	int n;
	cin >> n;
	for (int j = 1; j < n; ++j) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	int delta = 0;
	for (int j = 0; j < n; ++j)
		delta = max(delta, res[j] + 1);
	printf("%d\n", delta);
	for (int j = 0; j < n; ++j)
		printf("%d ", 1 + res[j]);
}