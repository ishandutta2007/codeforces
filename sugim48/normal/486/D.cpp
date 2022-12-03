#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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

ll foo(int u, int _u, vector< vector<int> >& G, vector<int>& a, int r, int d) {
	ll res = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == _u || i_i(a[v], v) < i_i(a[r], r) || a[v] - a[r] > d) continue;
		res = (res * (1 + foo(v, u, G, a, r, d))) % MOD;
	}
	return res;
}

int main() {
	int d, n; cin >> d >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector< vector<int> > G(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		G[u - 1].push_back(v - 1);
		G[v - 1].push_back(u - 1);
	}
	ll ans = 0;
	for (int u = 0; u < n; u++)
		ans = (ans + foo(u, -1, G, a, u, d)) % MOD;
	cout << ans << endl;
}