#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
typedef vector<vector<bool> > grid;

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll pow_mod(ll x, ll n, ll M) {
	x = (x % M + M) % M;
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

ll inv_mod(ll x, ll p) {
	return pow_mod(x, p - 2, p);
}

int main() {
	ll mod = MOD - 1;
	ll x = 1;
	int sign = -1;
	int N; cin >> N;
	while (N--) {
		ll y; scanf("%lld", &y);
		x = x * (y % mod) % mod;
		if (y % 2 == 0) sign = 1;
	}
	if (!x) x = mod;
	ll a = (pow_mod(2, x - 1, MOD) + sign) * inv_mod(3, MOD) % MOD;
	ll b = pow_mod(2, x - 1, MOD);
	cout << (a + MOD) % MOD << '/' << (b + MOD) % MOD << endl;
}