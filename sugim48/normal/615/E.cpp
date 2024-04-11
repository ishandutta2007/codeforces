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

ll MOD = 1234576891234601LL;
ll _MOD = 1000000009;
double EPS = 1e-10;

int x[6] = {-1, -2, -1, 1, 2, 1};
int y[6] = {2, 0, -2, -2, 0, 2};

ll f(ll x) {
	return x * (x + 1) * 3 + 1;
}

int main() {
	ll n; cin >> n;
	if (n == 0) {
		cout << 0 << ' ' << 0 << endl;
		return 0;
	}
	ll lb = 0, ub = 1000000000;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		if (f(mid) <= n) lb = mid;
		else ub = mid;
	}
	ll m = lb;
	vector<ll> a(6);
	a[0] = m * (m - 1) / 2;
	a[1] = a[2] = a[3] = a[4] = m * (m + 1) / 2;
	a[5] = (m + 1) * (m + 2) / 2;
	ll z = n - f(m), k;
	k = min(z, m); z -= k; a[0] += k;
	k = min(z, m + 1); z -= k; a[1] += k;
	k = min(z, m + 1); z -= k; a[2] += k;
	k = min(z, m + 1); z -= k; a[3] += k;
	k = min(z, m + 1); z -= k; a[4] += k;
	k = min(z, m + 2); z -= k; a[5] += k;
	ll X = 0, Y = 0;
	for (int i = 0; i < 6; i++) {
		X += a[i] * x[i];
		Y += a[i] * y[i];
	}
	cout << X << ' ' << Y << endl;
}