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

int pow_mod(ll x, ll n, int m) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * x) % m;
		x = (x * x) % m;
	}
	return res;
}

int main() {
	int n; cin >> n;
	cout << (pow_mod(3, n * 3, MOD) - pow_mod(7, n, MOD) + MOD) % MOD << endl;
}