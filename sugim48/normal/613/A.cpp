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
double EPS = 1e-9;

int main() {
	int n, x0, y0;
	cin >> n >> x0 >> y0;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		x[i] -= x0;
		y[i] -= y0;
	}
	double mi = DBL_MAX, ma = DBL_MIN;
	for (int i = 0; i < n; i++) {
		double x1 = x[i], y1 = y[i];
		double x2 = x[(i + 1) % n], y2 = y[(i + 1) % n];
		double r1 = sqrt(x1 * x1 + y1 * y1);
		double r2 = sqrt(x2 * x2 + y2 * y2);
		mi = min(mi, min(r1, r2));
		ma = max(ma, max(r1, r2));
		double dx = x1 - x2, dy = y1 - y2;
		double d = sqrt(dx * dx + dy * dy);
		double h = abs(x1 * y2 - x2 * y1) / d;
		if (sqrt(r1 * r1 - h * h) + sqrt(r2 * r2 - h * h) <= d + EPS)
			mi = min(mi, h);
	}
	double ans = (ma * ma - mi * mi) * M_PI;
	printf("%.15f\n", ans);
}