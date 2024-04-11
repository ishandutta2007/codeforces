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

void dfs(int u, int _u, vector< vector<int> >& G, vector<int>& num) {
	num[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == _u) continue;
		dfs(v, u, G, num);
		num[u] += num[v];
	}
}

int main() {
	int n; cin >> n;
	vector<int> a(n - 1), b(n - 1), l(n - 1);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &a[i], &b[i], &l[i]);
		a[i]--; b[i]--;
	}
	vector< vector<int> > G(n);
	for (int i = 0; i < n - 1; i++) {
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	vector<int> num(n);
	dfs(0, -1, G, num);
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		ll x = min(num[a[i]], num[b[i]]);
		sum += x * (n - x) * l[i];
	}
	int m; cin >> m;
	while (m--) {
		int r, w; scanf("%d%d", &r, &w);
		r--;
		ll x = min(num[a[r]], num[b[r]]);
		sum += x * (n - x) * (w - l[r]);
		l[r] = w;
		double ans = sum;
		ans /= (ll)n * (n - 1) / 2;
		ans *= 3;
		printf("%.10f\n", ans);
	}
}