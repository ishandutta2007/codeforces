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

ll gcd(ll a, ll b) {
	if (b == 0) return abs(a);
	else return gcd(b, a % b);
}

int main() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	ll ans = (ll)n * (n - 1) * (n - 2) / 6;
	for (int i = 0; i < n; i++) {
		map<i_i, int> mp;
		for (int j = 0; j < n; j++) {
			int dx = x[j] - x[i], dy = y[j] - y[i];
			if (dx < 0 || (dx == 0 && dy <= 0))
				continue;
			int d = gcd(dx, dy);
			dx /= d; dy /= d;
			mp[i_i(dx, dy)]++;
		}
		for (auto it = mp.begin(); it != mp.end(); it++) {
			int k = it->second;
			ans -= k * (k - 1) / 2;
		}
	}
	cout << ans << endl;
}