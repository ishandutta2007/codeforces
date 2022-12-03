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
 
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};
 
int N;
vector<int> G[30];
vector<ll> y, x;
ll len = 1LL<<40;
 
void dfs(int u, int p, int k) {
	for (int v: G[u]) {
		if (v == p) continue;
		k = (k + 1) % 4;
		y[v] = y[u] + len * dy[k];
		x[v] = x[u] + len * dx[k];
		len /= 2;
		dfs(v, u, (k + 2) % 4);
	}
}
 
int main() {
	cin >> N;
	vector<int> d(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
		d[u]++; d[v]++;
	}
	for (int u = 0; u < N; u++) if (d[u] > 4) {
		cout << "NO" << endl;
		return 0;
	}
	y.resize(N);
	x.resize(N);
	dfs(0, -1, 0);
	vector<ll> Y = y, X = x;
	sort(Y.begin(), Y.end());
	sort(X.begin(), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for (int u = 0; u < N; u++) {
		y[u] = lower_bound(Y.begin(), Y.end(), y[u]) - Y.begin();
		x[u] = lower_bound(X.begin(), X.end(), x[u]) - X.begin();
	}
	cout << "YES" << endl;
	for (int u = 0; u < N; u++)
		cout << x[u] << ' ' << y[u] << endl;
}