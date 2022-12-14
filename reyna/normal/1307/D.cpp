
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

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int q[N], d0[N], d1[N], o0[N], o1[N];
vector<int> adj[N];
void bfs(int src, int d[N]) {
	for (int j = 0; j < N; ++j) d[j] = 1e9;
	d[src] = 0;
	int h = 0, t = 0;
	q[t++] = src;
	while (h < t) {
		int v = q[h++];
		for (int u : adj[v]) if (d[u] > d[v] + 1) {
			d[u] = d[v] + 1;
			q[t++] = u;
		}
	}
}
int cmp(int x, int y) { return d0[x] > d0[y]; }
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int j = 0; j < k; ++j) {
		int x;
		cin >> x;
		--x;
		o0[j] = o1[j] = x;
	}
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bfs(0, d0);
	bfs(n-1, d1);
	sort(o0, o0 + k, cmp);
	int res = 0;
	for (int j = 0; j < k - 1; ++j) {
			int x = o0[j], y = o0[j+1];
			if (x != y) {
				res = max(res, min(d0[x] + d1[y], d0[y] + d1[x]) + 1);
			}
	}
	res = min(res, d0[n-1]);
	cout << res << endl;
}