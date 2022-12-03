#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int m;

int dfs(int u, int p, vector<vector<int> >& G, vector<bool>& a, vector<vector<int> >& g) {
	int sz = a[u];
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) continue;
		int x = dfs(v, u, G, a, g);
		sz += x;
		if (x != 0 && x != m) {
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	return sz;
}

void _dfs(int u, int p, int x, vector<vector<int> >& g, vector<int>& d) {
	d[u] = x;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == p) continue;
		_dfs(v, u, x + 1, g, d);
	}
}

int main() {
	int n; cin >> n >> m;
	vector<vector<int> > G(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<bool> a(n);
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		if (m == 1) {
			cout << x << endl << 0 << endl;
			return 0;
		}
		x--;
		a[x] = true;
	}
	vector<vector<int> > g(n);
	dfs(0, -1, G, a, g);
	int s;
	for (int u = 0; u < n; u++)
		if (!g[u].empty())
			s = u;
	vector<int> ds(n, -1);
	_dfs(s, -1, 0, g, ds);
	int x = s;
	for (int u = 0; u < n; u++)
		if (ds[u] > ds[x])
			x = u;
	vector<int> dx(n, -1);
	_dfs(x, -1, 0, g, dx);
	int y = x;
	for (int u = 0; u < n; u++)
		if (dx[u] > dx[y])
			y = u;
	vector<int> dy(n, -1);
	_dfs(y, -1, 0, g, dy);
	int ma = dx[y];
	for (int u = 0; u < n; u++)
		if (dx[u] == ma || dy[u] == ma) {
			cout << u + 1 << endl;
			break;
		}
	int ans = -ma;
	for (int u = 0; u < n; u++)
		ans += g[u].size();
	cout << ans << endl;
	/*cout << endl;
	for (int u = 0; u < n; u++)
		cout << ds[u] << ' ';
	cout << endl;
	for (int u = 0; u < n; u++)
		cout << dx[u] << ' ';
	cout << endl;
	for (int u = 0; u < n; u++)
		cout << dy[u] << ' ';
	cout << endl;*/
}