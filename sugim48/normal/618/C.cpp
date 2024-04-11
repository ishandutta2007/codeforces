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

ll f(ll x0, ll y0, ll x1, ll y1, ll x2, ll y2) {
	ll dx1 = x1 - x0, dy1 = y1 - y0;
	ll dx2 = x2 - x0, dy2 = y2 - y0;
	return abs(dx1 * dy2 - dx2 * dy1);
}

int main() {
	int n; cin >> n;
	vector<ll> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	vector<ll_ll> xy(n);
	map<ll_ll, int> mp;
	for (int i = 0; i < n; i++) {
		xy[i] = ll_ll(x[i], y[i]);
		mp[xy[i]] = i;
	}
	sort(xy.begin(), xy.end());
	for (int i = 0; i < n; i++) {
		x[i] = xy[i].first;
		y[i] = xy[i].second;
	}
	int _i; ll mi = LLONG_MAX;
	for (int i = 2; i < n; i++) {
		ll z = f(x[i], y[i], x[0], y[0], x[1], y[1]);
		if (0 < z && z < mi) {
			_i = i;
			mi = z;
		}
	}
	cout << mp[xy[0]] + 1 << ' ' << mp[xy[1]] + 1 << ' ' << mp[xy[_i]] + 1 << endl;
}