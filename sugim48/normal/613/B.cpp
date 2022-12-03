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
	int n, A, cf, cm; ll m;
	cin >> n >> A >> cf >> cm >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<i_i> ai(n);
	for (int i = 0; i < n; i++)
		ai[i] = i_i(a[i], i);
	sort(ai.begin(), ai.end());
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		a[i] = ai[i].first;
		p[ai[i].second] = i;
	}
	vector<ll> sum(n + 1);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	int _k, _lb; ll ma = -1;
	for (int k = n; k >= 0; k--) {
		int lb = 0, ub = A + 1;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			int i = lower_bound(a.begin(), a.begin() + k, mid) - a.begin();
			if (sum[i] + m >= (ll)i * mid) lb = mid;
			else ub = mid;
		}
		ll x = (ll)cf * (n - k) + (ll)cm * lb;
		if (x > ma) {
			_k = k;
			_lb = lb;
			ma = x;
		}
		if (k - 1 >= 0 && A - a[k - 1] <= m)
			m -= A - a[k - 1];
		else break;
	}
	cout << ma << endl;
	for (int i = 0; i < n; i++)
		printf("%d ", p[i] < _k ? max(_lb, a[p[i]]) : A);
	cout << endl;
}