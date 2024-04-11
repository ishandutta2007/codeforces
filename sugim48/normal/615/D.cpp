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
#include <random>
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

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

int pow_mod(ll x, ll n, int m) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * x) % m;
		x = (x * x) % m;
	}
	return res;
}

int main() {
	vector<int> a(200001);
	int m; cin >> m;
	while (m--) {
		int p; cin >> p;
		a[p]++;
	}
	ll x = 1;
	bool unko = false;
	for (int p = 2; p <= 200000; p++) {
		if (!a[p]) continue;
		if (!unko && (a[p] + 1) % 2 == 0) {
			unko = true;
			x = x * ((a[p] + 1) / 2) % (MOD - 1);
		}
		else x = x * (a[p] + 1) % (MOD - 1);
	}
	ll ans = 1;
	for (int p = 2; p <= 200000; p++) {
		if (!a[p]) continue;
		ll y;
		if (unko) y = x * a[p] % (MOD - 1);
		else y = x * (a[p] / 2) % (MOD - 1);
		ans = ans * pow_mod(p, y, MOD) % MOD;
	}
	cout << ans << endl;
}