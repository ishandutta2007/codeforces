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

ll f(ll n, ll m) {
	return n * (n + 1) * (m * 3 - n + 1) / 6;
}

int main() {
	ll x; cin >> x;
	ll prev = x + 1;
	vector<ll_ll> ans;
	for (ll n = 1; n < prev; n++) {
		ll lb = n, ub = prev;
		while (ub - lb > 1) {
			ll mid = (lb + ub) / 2;
			if (f(n, mid) <= x) lb = mid;
			else ub = mid;
		}
		if (f(n, lb) == x) {
			ans.push_back(ll_ll(n, lb));
			if (n < lb) ans.push_back(ll_ll(lb, n));
		}
		prev = ub;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
}