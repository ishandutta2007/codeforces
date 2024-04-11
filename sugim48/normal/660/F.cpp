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
struct edge { int u, v; ll w; };

int const MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-12;
int INF = INT_MAX / 2;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<ll> sum(N + 1), unko(N + 1);
	rep(i, N) {
		sum[i + 1] = sum[i] + a[i];
		unko[i + 1] = unko[i] + (ll)(i + 1) * a[i];
	}
	vector<ll> val(N + 1);
	rep(i, N + 1) val[i] = i * sum[i] - unko[i];
	int M = 0;
	vector<ll_ll> v;
	ll ans = 0;
	for (int i = 0; i <= N; i++) {
		while (M >= 2 && (v[M - 1].second - v[M - 2].second) * (i - v[M - 1].first)
				<= (val[i] - v[M - 1].second) * (v[M - 1].first - v[M - 2].first))
				v.pop_back(), M--;
		v.pb(ll_ll(i, val[i])); M++;
		int lb = 0, ub = M - 1;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (v[mid].second - sum[i] * v[mid].first < v[mid + 1].second - sum[i] * v[mid + 1].first) lb = mid;
			else ub = mid;
		}
		ll ma = v[lb].second - sum[i] * v[lb].first;
		if (lb + 1 < M) ma = max(ma, v[lb + 1].second - sum[i] * v[lb + 1].first);
		ans = max(ans, ma + unko[i]);
	}
	cout << ans << endl;
}