
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
#define int long long
typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int par[N], n, m, mark[N], sz[N], eu[N], ev[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	par[u] = v;
}
int solve(int a, int b) {
	int res = 0;
	for (int j = 0; j < n; ++j) par[j] = j, sz[j] = 0;
	for (int j = 0; j < m; ++j) {
		int u = eu[j], v = ev[j];
		if (u != a && v != a) unite(u, v);
	}
	for (int j = 0; j < n; ++j) mark[j] = 0;
	for (int j = 0; j < n; ++j) sz[find(j)]++;
	for (int j = 0; j < m; ++j) {
		int u = eu[j], v = ev[j];
		if (v == a) swap(u, v);
		if (u == a) {
			if (find(v) != find(b)) {
				res += (1 - mark[find(v)]) * sz[find(v)];
				mark[find(v)] = 1;
			}
		}
	}
	return res;
}
int32_t main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int pa, pb;
		cin >> n >> m >> pa >> pb; --pa, --pb;
		for (int j = 0; j < m; ++j) {
			cin >> eu[j] >> ev[j];
			--eu[j], --ev[j];
		}
		int a = pa, b = pb;
		int x = solve(a, b);
		int y = solve(b, a);
		cout << x * y << '\n';
	}
		
		
}