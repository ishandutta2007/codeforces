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
#include <random>
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

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> > G(n);
	while (m--) {
		int u, v; cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> a(n, 1);
	for (int u = 0; u < n; u++)
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			if (v < u) a[u] = max(a[u], a[v] + 1);
		}
	ll ma = 0;
	for (int u = 0; u < n; u++)
		ma = max(ma, (ll)a[u] * G[u].size());
	cout << ma << endl;
}