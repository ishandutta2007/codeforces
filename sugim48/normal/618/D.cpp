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

void f(int u, int p, vector<vector<int> >& G, vector<vector<int> >& a) {
	vector<int> dp(3);
	dp[1] = dp[2] = INT_MIN / 10;
	for (int v: G[u]) {
		if (v == p) continue;
		f(v, u, G, a);
		vector<int> _dp(3, INT_MIN / 10);
		for (int x = 0; x <= 2; x++)
			for (int y = 0; y <= 1; y++)
				if (x + y <= 2)
					_dp[x + y] = max(_dp[x + y], dp[x] + a[v][y]);
		dp = _dp;
	}
	a[u][0] = max(dp[0], max(dp[1], dp[2]));
	a[u][1] = max(dp[0], dp[1]) + 1;
}

int main() {
	int N; ll x, y; cin >> N >> x >> y;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (x == y) {
		cout << (N - 1) * x << endl;
		return 0;
	}
	if (x > y) {
		bool ok = true;
		for (int u = 0; u < N; u++)
			if (G[u].size() == N - 1)
				ok = false;
		if (ok) cout << (N - 1) * y << endl;
		else cout << (N - 2) * y + x << endl;
		return 0;
	}
	vector<vector<int> > a(N, vector<int>(2));
	f(0, -1, G, a);
	int M = a[0][0];
	cout << M * x + (N - 1 - M) * y << endl;
}