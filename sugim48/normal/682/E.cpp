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

ll f(int x0, int y0, int x1, int y1, int x2, int y2) {
	ll dx1 = x1 - x0, dy1 = y1 - y0;
	ll dx2 = x2 - x0, dy2 = y2 - y0;
	return abs(dx1 * dy2 - dy1 * dx2);
}

int main() {
	int N; ll S; cin >> N >> S;
	vector<ll> x(N), y(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	int i0 = 0, i1 = 1, i2 = 2;
	int t = 0;
	while (t < 3) {
		int _i = i2;
		ll ma = f(x[i0], y[i0], x[i1], y[i1], x[i2], y[i2]);
		for (int i = 0; i < N; i++) {
			ll S = f(x[i0], y[i0], x[i1], y[i1], x[i], y[i]);
			if (S > ma) {
				_i = i;
				ma = S;
			}
		}
		if (_i == i2) t++;
		else t = 0;
		i2 = i0; i0 = i1; i1 = _i;
	}
	int X0 = x[i1] + x[i2] - x[i0]; int Y0 = y[i1] + y[i2] - y[i0];
	int X1 = x[i2] + x[i0] - x[i1]; int Y1 = y[i2] + y[i0] - y[i1];
	int X2 = x[i0] + x[i1] - x[i2]; int Y2 = y[i0] + y[i1] - y[i2];
	cout << X0 << ' ' << Y0 << endl;
	cout << X1 << ' ' << Y1 << endl;
	cout << X2 << ' ' << Y2 << endl;
}