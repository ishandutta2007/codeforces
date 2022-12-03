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

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

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

int main() {
	ll n, dx, dy; int m;
	cin >> n >> m >> dx >> dy;
	vector<int> a(n);
	while (m--) {
		ll x, y; cin >> x >> y;
		ll t = y * mod_inverse(dy, n) % n;
		ll x0 = (x - t * dx) % n;
		if (x0 < 0) x0 += n;
		a[x0]++;
	}
	int maxi = 0;
	for (int x = 0; x < n; x++)
		maxi = max(maxi, a[x]);
	for (int x = 0; x < n; x++)
		if (a[x] == maxi) {
			cout << x << ' ' << 0 << endl;
			break;
		}
}