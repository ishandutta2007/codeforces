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

#define rep(i, N) for (int i = 0; i < N; i++)

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	ll x0, y0; cin >> x0 >> y0;
	vector<char> c(N);
	vector<ll> x(N), y(N);
	rep(i, N) {
		scanf("%*c%c%lld%lld", &c[i], &x[i], &y[i]);
		x[i] -= x0; y[i] -= y0;
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (x[i] == 0 && y[i] > 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'R' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (x[i] == 0 && y[i] < 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'R' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (y[i] == 0 && x[i] > 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'R' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (y[i] == 0 && x[i] < 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'R' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (abs(x[i]) == abs(y[i]) && x[i] > 0 && y[i] > 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'B' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (abs(x[i]) == abs(y[i]) && x[i] > 0 && y[i] < 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'B' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (abs(x[i]) == abs(y[i]) && x[i] < 0 && y[i] > 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'B' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	{
		ll mi = LLONG_MAX;
		bool ok = false;
		rep(i, N)
			if (abs(x[i]) == abs(y[i]) && x[i] < 0 && y[i] < 0) {
				ll d = abs(x[i]) + abs(y[i]);
				if (d < mi) {
					mi = d;
					ok = (c[i] == 'B' || c[i] == 'Q');
				}
			}
		if (ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}