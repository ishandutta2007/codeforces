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
int INF = INT_MAX;

ll solve(ll x, ll y, ll p, ll q) {
	ll lb = 0, ub = INF;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		ll dx = mid * p - x;
		ll dy = mid * q - y;
		if (0 <= dx && dx <= dy) ub = mid;
		else lb = mid;
	}
	if (ub == INF) return -1;
	return ub * q - y;
}

int main() {
	int T; cin >> T;
	while (T--) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;
		cout << solve(x, y, p, q) << endl;
	}
}