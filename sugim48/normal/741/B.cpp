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

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int N, M, W;
	cin >> N >> M >> W;
	vector<int> w(N), b(N);
	rep(i, N) cin >> w[i];
	rep(i, N) cin >> b[i];
	union_find uf(N);
	while (M--) {
		int u, v; scanf("%d%d", &u, &v);
		uf.unite(u - 1, v - 1);
	}
	vector<vector<i_i> > a(N);
	rep(i, N) a[uf.find(i)].pb(i_i(w[i], b[i]));
	vector<int> dp(W + 1);
	rep(i, N) {
		if (a[i].empty()) continue;
		vector<int> _dp = dp;
		int ww = 0, bb = 0;
		for (i_i wb: a[i]) {
			int w = wb.first, b = wb.second;
			for (int x = 0; x + w <= W; x++)
				_dp[x + w] = max(_dp[x + w], dp[x] + b);
			ww += w; bb += b;
		}
		for (int x = 0; x + ww <= W; x++)
			_dp[x + ww] = max(_dp[x + ww], dp[x] + bb);
		dp = _dp;
	}
	cout << dp[W] << endl;
}