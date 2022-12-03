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

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

void dfs(int u, int p, vector<vector<int> >& G, vector<bool>& a, vector<int>& path) {
	path.push_back(u);
	a[u] = !a[u];
	for (int v: G[u]) {
		if (v == p) continue;
		dfs(v, u, G, a, path);
		path.push_back(u);
		a[u] = !a[u];
		if (a[v]) {
			path.push_back(v);
			a[v] = !a[v];
			path.push_back(u);
			a[u] = !a[u];
		}
	}
}

int main() {
	int N; cin >> N;
	vector<bool> a(N);
	for (int u = 0; u < N; u++) {
		int x; scanf("%d", &x);
		a[u] = (x == -1);
	}
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> path;
	dfs(0, -1, G, a, path);
	if (!a[0]) path.pop_back();
	for (int u: path) printf("%d ", u + 1);
	cout << endl;
}