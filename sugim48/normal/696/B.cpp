#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
typedef vector<vector<bool> > grid;

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void dfs_dep(int u, vector<vector<int> >& G, vector<int>& dep) {
	for (int v: G[u]) {
		dep[v] = dep[u] + 1;
		dfs_dep(v, G, dep);
	}
}

void dfs_sz(int u, vector<vector<int> >& G, vector<int>& sz) {
	sz[u] = 1;
	for (int v: G[u]) {
		dfs_sz(v, G, sz);
		sz[u] += sz[v];
	}
}

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	for (int u = 1; u < N; u++) {
		int p; scanf("%d", &p); p--;
		G[p].push_back(u);
	}
	vector<int> dep(N), sz(N);
	dfs_dep(0, G, dep);
	dfs_sz(0, G, sz);
	for (int u = 0; u < N; u++) {
		double ans = 1 + dep[u] + (N - dep[u] - sz[u]) / 2.0;
		printf("%.8f ", ans);
	}
	cout << endl;
}