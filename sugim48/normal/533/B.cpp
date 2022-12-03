#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
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

vector<int> G[200000];
ll a[200000], b[200000], c[200000];

void dfs(int u) {
	ll x = 0, y = LLONG_MIN;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		dfs(v);
		ll _x = max(x + b[v], y + c[v]);
		ll _y = max(y + b[v], x + c[v]);
		x = _x; y = _y;
	}
	b[u] = x;
	c[u] = max(y, x + a[u]);
}

int main() {
	int n; cin >> n;
	for (int u = 0; u < n; u++) {
		int p; cin >> p >> a[u];
		if (p != -1) G[p - 1].push_back(u);
	}
	dfs(0);
	cout << max(b[0], c[0]) << endl;
}