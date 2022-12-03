#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
	int n; ll x, y; cin >> n >> x >> y;
	while (n--) {
		ll a; scanf("%I64d", &a);
		ll lb = -1, ub = LLONG_MAX / 10;
		while (ub - lb > 1) {
			ll mid = (lb + ub) / 2;
			if (mid / y + mid / x >= a) ub = mid;
			else lb = mid;
		}
		ll t = ub;
		ll tx = t / y * y, ty = t / x * x;
		if (tx == ty) printf("Both\n");
		else if (tx > ty) printf("Vanya\n");
		else if (tx < ty) printf("Vova\n");
	}
}