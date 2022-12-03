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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int> > G(N);
	vector<vector<int> > d(N, vector<int>(N, INF));
	rep(u, N) d[u][u] = 0;
	while (M--) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		G[u].pb(v); G[v].pb(u);
		d[u][v] = d[v][u] = 1;
	}
	rep(k, N) rep(u, N) rep(v, N)
		d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
	double ans = 0;
	rep(x, N) {
		double sum = 0;
		rep(k, N) {
			vector<double> p(N);
			bool ok = false;
			rep(u, N) if (d[x][u] == k) for (int v: G[u])
				ok = true, p[v] += 1.0 / N / G[u].size();
			if (!ok) continue;
			double ma = 1.0 / N;
			vector<int> vs;
			rep(u, N) if (k - 1 <= d[x][u] && d[x][u] <= k + 1) vs.pb(u);
			vector<double> q(N);
			rep(y, N) {
				double sum = 0;
				for (int u: vs) {
					int _k = d[y][u];
					if (p[u] > q[_k]) sum += p[u] - q[_k], q[_k] = p[u];
				}
				for (int u: vs) {
					int _k = d[y][u];
					q[_k] = 0;
				}
				ma = max(ma, sum);
			}
			sum += ma;
		}
		ans = max(ans, sum);
	}
	printf("%.10f\n", ans);
}