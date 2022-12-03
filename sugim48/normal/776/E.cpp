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
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
	vector<bool> p(1000001, true);
	for (int x = 2; x <= 1000000; x++)
		if (p[x])
			for (int y = x * 2; y <= 1000000; y++)
				p[y] = false;
	vector<ll> ps;
	for (int x = 2; x <= 1000000; x++)
		ps.pb(x);
	ll x, T; cin >> x >> T;
	T = (T + 1) / 2;
	while (T--) {
		if (x == 1) break;
		ll y = x;
		for (ll p: ps) {
			if ((ll)p * p > y) break;
			if (y % p) continue;
			while (y % p == 0) y /= p;
			x = x / p * (p - 1);
		}
		if (y > 1) x = x / y * (y - 1);
	}
	cout << x % MOD << endl;
}