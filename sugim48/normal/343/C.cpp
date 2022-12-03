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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

ll f(ll x, ll l, ll r) {
	l -= x; r -= x;
	if (l <= 0 && r <= 0) return -l;
	if (l >= 0 && r >= 0) return r;
	return min(-l, r) - l + r;
}

int main() {
	int n, m; cin >> n >> m;
	vector<ll> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];
	vector<ll> p(m);
	for (int j = 0; j < m; j++)
		cin >> p[j];
	ll lb = -1, ub = LLONG_MAX / 2;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		int j = 0;
		for (int i = 0; i < n && j < m; i++) {
			ll l = p[j];
			while (j < m && f(h[i], l, p[j]) <= mid) j++;
		}
		if (j == m) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
}