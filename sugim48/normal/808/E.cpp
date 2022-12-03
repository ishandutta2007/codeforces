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
#include <unordered_map>
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
struct edge { int src, dst; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-9;
ll INF = LLONG_MAX / 2;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int> > a(4);
	while (N--) {
		int w, x; scanf("%d%d", &w, &x);
		a[w].pb(x);
	}
	vector<vector<ll> > sum(4);
	for (int w = 1; w <= 3; w++) {
		vector<int>& v = a[w];
		for (; v.size() < M; v.pb(0));
		sort(v.rbegin(), v.rend());
		sum[w] = vector<ll>(M + 1);
		rep(i, M) sum[w][i + 1] = sum[w][i] + v[i];
	}
	vector<ll> unko(M + 1);
	for (int m = 0; m <= M; m++) {
		int lb = 0, ub = m / 2;
		while (ub - lb > 30) {
			int mid1 = (lb * 2 + ub) / 3;
			int mid2 = (lb + ub * 2) / 3;
			ll f1 = sum[1][m - mid1 * 2] + sum[2][mid1];
			ll f2 = sum[1][m - mid2 * 2] + sum[2][mid2];
			if (f1 > f2) ub = mid2;
			else lb = mid1;
		}
		for (int i = lb; i <= ub; i++)
			unko[m] = max(unko[m], sum[1][m - i * 2] + sum[2][i]);
	}
	ll ans = 0;
	for (int i = 0; i <= M; i++)
		ans = max(ans, unko[i] + sum[3][(M - i) / 3]);
	cout << ans << endl;
}