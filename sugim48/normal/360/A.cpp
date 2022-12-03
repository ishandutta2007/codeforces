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
double INF = FLT_MAX;

int main() {
	int n, m; cin >> n >> m;
	vector<int> t(m), l(m), r(m), d(m);
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> l[i] >> r[i] >> d[i];
		l[i]--;
	}
	vector<int> a(n, 2000000000);
	for (int i = m - 1; i >= 0; i--) {
		if (t[i] == 1)
			for (int x = l[i]; x < r[i]; x++)
				a[x] -= d[i];
		if (t[i] == 2)
			for (int x = l[i]; x < r[i]; x++)
				a[x] = min(a[x], d[i]);
	}
	for (int x = 0; x < n; x++) {
		a[x] = min(a[x], 1000000000);
		a[x] = max(a[x], -1000000000);
	}
	vector<int> _a = a;
	bool ok = true;
	for (int i = 0; i < m; i++) {
		if (t[i] == 1)
			for (int x = l[i]; x < r[i]; x++)
				a[x] += d[i];
		if (t[i] == 2) {
			int ma = INT_MIN;
			for (int x = l[i]; x < r[i]; x++)
				ma = max(ma, a[x]);
			if (ma != d[i]) ok = false;
		}
	}
	if (ok) {
		cout << "YES" << endl;
		for (int x = 0; x < n; x++)
			cout << _a[x] << ' ';
		cout << endl;
	}
	else cout << "NO" << endl;
}