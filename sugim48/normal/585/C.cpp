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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v, c; };

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

ll f(ll a1, ll a2, ll b1, ll b2) {
	ll k = LLONG_MAX;
	if (b1) k = min(k, a1 / b1);
	if (b2) k = min(k, a2 / b2);
	return k;
}

int main() {
	ll a, b; cin >> a >> b;
	if (gcd(a, b) != 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	ll x, y;
	extgcd(b, a, x, y);
	x *= -1;
	y *= -1;
	y += b;
	while (x < 0) {
		x += a;
		y -= b;
	}
	while (x >= a) {
		x -= a;
		y += b;
	}
	ll a1 = a - x, a2 = y;
	ll b1 = x, b2 = b - y;
	vector<ll> ans;
	for (;;) {
		if (a1 >= b1 && a2 >= b2) {
			ll k = f(a1, a2, b1, b2);
			a1 -= k * b1;
			a2 -= k * b2;
			ans.push_back(-k);
		}
		else if (a1 <= b1 && a2 <= b2) {
			ll k = f(b1, b2, a1, a2);
			b1 -= k * a1;
			b2 -= k * a2;
			ans.push_back(k);
		}
		else break;
	}
	if (a1==1 && a2==0 && b1==0 && b2==1);
	else {
		cout << "Impossible" << endl;
		return 0;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		ll k = ans[i];
		if (k > 0) cout << k << 'A';
		else cout << -k << 'B';
	}
	cout << endl;
}