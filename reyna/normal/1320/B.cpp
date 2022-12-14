
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
int q[N], d[N], p[N];
vector<int> adj[N], in[N];
void bfs(int src) {
	int h = 0, t = 0;
	memset(d, 63, sizeof d);
	d[src] = 0;
	q[t++] = src;
	while (h < t) {
		int v = q[h++];
		for (int u : in[v])
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				q[t++] = u;
			}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		in[v].pb(u);
		adj[u].pb(v);
	}
	int k;
	cin >> k;
	for (int j = 0; j < k; ++j)
		cin >> p[j], --p[j];
	bfs(p[k-1]);
	int mn = 0, mx = 0;
	for (int j = 0; j < k - 1; ++j) {
		int flag = 0, u = p[j], v = p[j+1];
		int cur_dis = d[v];
		for (int x : adj[u]) {
			if (x != v && d[u] == d[x] + 1) {
				flag = 1;
			}
		}
		mx += flag;
		if (d[u] != d[v] + 1) {
			++mn;
		}
	}
	cout << mn << ' ' << mx << endl;
	
}