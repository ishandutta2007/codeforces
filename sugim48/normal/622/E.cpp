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

void dfs(int u, int p, int x, vector<vector<int> >& G, vector<int>& a) {
	bool leaf = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) continue;
		leaf = false;
		dfs(v, u, x + 1, G, a);
	}
	if (leaf) a[x]++;
}

int _dfs(int u, int p, vector<vector<int> >& G) {
	int sum = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) continue;
		sum += _dfs(v, u, G);
	}
	return sum;
}

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ma = 0;
	for (int i = 0; i < G[0].size(); i++) {
		int u = G[0][i], n = _dfs(u, 0, G);
		vector<int> a(n);
		dfs(u, 0, 0, G, a);
		for (int i = 0; i < n; i++)
			if (a[i]) a[i + 1] += a[i] - 1;
		for (int i = 0; i < n; i++)
			if (a[i])
				ma = max(ma, i);
	}
	cout << ma + 1 << endl;
}