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
#include <unordered_set>
#include <complex>
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
typedef complex<double> C;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 2;
double EPS = 1e-10;

void dfs_A(int u, int p, vector<vector<int> >& G, vector<int>& a, vector<int>& A) {
	A[u] ^= a[u];
	for (int v: G[u]) if (v != p) {
		A[v] ^= A[u];
		dfs_A(v, u, G, a, A);
	}
}

ll ans = 0;

void dfs(int u, int p, vector<vector<int> >& G, vector<int>& a, vector<int>& A, vector<vector<int> >& dp0, vector<vector<int> >& dp1) {
	ans += a[u];
	rep(i, 20) if (A[u]>>i & 1) dp1[u][i]++; else dp0[u][i]++;
	for (int v: G[u]) if (v != p) {
		dfs(v, u, G, a, A, dp0, dp1);
		rep(i, 20)
			if (a[u]>>i & 1)
				ans += (1<<i) * ((ll)dp0[u][i] * dp0[v][i] + (ll)dp1[u][i] * dp1[v][i]);
			else
				ans += (1<<i) * ((ll)dp0[u][i] * dp1[v][i] + (ll)dp1[u][i] * dp0[v][i]);
		rep(i, 20) dp0[u][i] += dp0[v][i], dp1[u][i] += dp1[v][i];
	}
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(u, N) scanf("%d", &a[u]);
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].pb(v); G[v].pb(u);
	}
	vector<int> A(N);
	dfs_A(0, -1, G, a, A);
	vector<vector<int> > dp0(N, vector<int>(20)), dp1 = dp0;
	dfs(0, -1, G, a, A, dp0, dp1);
	cout << ans << endl;
}