#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
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

int main() {
	int n, m; cin >> n >> m;
	vector< vector<int> > G(n);
	while (m--) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
	}
	ll ans = 0;
	for (int u = 0; u < n; u++) {
		vector<int> a(n);
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			for (int j = 0; j < G[v].size(); j++) {
				int w = G[v][j];
				a[w]++;
			}
		}
		for (int v = 0; v < n; v++) {
			if (v == u) continue;
			ans += (ll)a[v] * (a[v] - 1) / 2;
		}
	}
	cout << ans << endl;
}