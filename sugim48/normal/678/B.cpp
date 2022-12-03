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

bool is_leap(int x) {
	if (x % 400 == 0) return true;
	if (x % 100 == 0) return false;
	if (x % 4 == 0) return true;
	return false;
}

int main() {
	int x0; cin >> x0;
	ll y = 0;
	for (int x = x0; ; x++) {
		if (y && y % 7 == 0 && is_leap(x0) == is_leap(x)) {
			cout << x << endl;
			break;
		}
		y += is_leap(x) ? 366 : 365;
	}
}