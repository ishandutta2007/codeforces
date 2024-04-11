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
double EPS = 1e-9;

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
	int n; cin >> n;
	if (n == 1) {
		cout << "YES" << endl;
		cout << 1 << endl;
		return 0;
	}
	if (n == 4) {
		cout << "YES" << endl;
		cout << "1\n3\n2\n4\n";
		return 0;
	}
	for (int i = 2; i < n; i++)
		if (n % i == 0) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	cout << 1 << endl;
	vector<int> a(n);
	for (int i = 1; i < n; i++) {
		ll x = mod_inverse(i, n);
		int y = (x * (i + 1) % n) % n;
		if (y == 0) y = n;
		cout << y << endl;
	}
}