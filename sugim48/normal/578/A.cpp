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
	ll a, b; cin >> a >> b;
	if (a < b) cout << -1 << endl;
	if (a == b) cout << a << endl;
	if (a > b) {
		ll lb = 1, ub = INT_MAX;
		while (ub - lb > 1) {
			ll mid = (lb + ub) / 2;
			if ((mid * 2 - 1) * b <= a) lb = mid;
			else ub = mid;
		}
		double ans = (double)(a + b) / (lb * 2);
		printf("%.15f\n", ans);
	}
}