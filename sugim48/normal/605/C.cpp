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

int main() {
	int n, p, q; cin >> n >> p >> q;
	vector<int> _a(n), _b(n);
	int amax = 0, bmax = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &_a[i], &_b[i]);
		amax = max(amax, _a[i]);
		bmax = max(bmax, _b[i]);
	}
	vector<d_i> pr(n);
	for (int i = 0; i < n; i++)
		pr[i] = d_i((double)_a[i] / _b[i], i);
	sort(pr.begin(), pr.end());
	vector<int> a(n + 2), b(n + 2);
	a[0] = 0; b[0] = 1;
	a[n + 1] = 1; b[n + 1] = 0;
	for (int i = 0; i < n; i++) {
		int j = pr[i].second;
		a[i + 1] = _a[j];
		b[i + 1] = _b[j];
	}
	stack<int> E;
	E.push(0);
	stack<d_d> P;
	P.push(d_d(0, 0));
	for (int i = 1; i < n + 2; i++) {
		for (;;) {
			d_d p = P.top();
			double x = p.first, y = p.second;
			if (a[i] * x + b[i] * y < 1) break;
			P.pop();
			E.pop();
		}
		int j = E.top();
		ll z = (ll)a[i] * b[j] - (ll)a[j] * b[i];
		if (z == 0) continue;
		double x = (double)(b[j] - b[i]) / z;
		double y = (double)(a[i] - a[j]) / z;
		E.push(i);
		P.push(d_d(x, y));
	}
	double ma = max((double)p / amax, (double)q / bmax);
	for (; !P.empty(); P.pop()) {
		double x = P.top().first, y = P.top().second;
		if (x >= 0 && y >= 0)
			ma = max(ma, p * x + q * y);
		// cout << x << ' ' << y << endl;
	}
	printf("%.10f\n", ma);
}