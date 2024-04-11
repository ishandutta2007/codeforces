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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll a[200010][2], b[200010][2];
vector<ll> al[200010][2], ar[200010][2];

void dfs(int u, vector<vector<int> >& G) {
	int m = G[u].size();
	al[u][0].assign(m + 1, 1);
	ar[u][0].assign(m + 1, 1);
	al[u][1].assign(m + 1, 1);
	ar[u][1].assign(m + 1, 1);
	for (int i = 0; i < m; i++) {
		int v = G[u][i];
		dfs(v, G);
		al[u][0][i + 1] = al[u][0][i] * a[v][0] % MOD;
		al[u][1][i + 1] = al[u][1][i] * (a[v][0] + a[v][1]) % MOD;
	}
	for (int i = m - 1; i >= 0; i--) {
		int v = G[u][i];
		ar[u][0][i] = ar[u][0][i + 1] * a[v][0] % MOD;
		ar[u][1][i] = ar[u][1][i + 1] * (a[v][0] + a[v][1]) % MOD;
	}
	a[u][0] = al[u][0][m];
	a[u][1] = al[u][1][m];
}

void _dfs(int u, vector<vector<int> >& G) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		b[v][0] = al[u][0][i] * ar[u][0][i + 1] % MOD * b[u][0] % MOD;
		b[v][1] = (b[v][0] + al[u][1][i] * ar[u][1][i + 1] % MOD * b[u][1]) % MOD;
		_dfs(v, G);
	}
}

int main() {
	int n; cin >> n;
	vector<vector<int> > G(n);
	for (int u = 1; u < n; u++) {
		int p; cin >> p;
		G[p - 1].push_back(u);
	}
	dfs(0, G);
	b[0][0] = b[0][1] = 1;
	_dfs(0, G);
	for (int u = 0; u < n; u++)
		cout << a[u][1] * b[u][1] % MOD << ' ';
	cout << endl;
}