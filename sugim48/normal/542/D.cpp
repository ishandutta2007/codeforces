#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
#include <unordered_map>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll solve(ll x) {
	vector<bool> p(1000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i <= 1000000; i++)
		if (p[i])
			for (int j = i * 2; j <= 1000000; j += i)
				p[j] = false;
	vector<int> ps;
	for (int i = 2; i <= 1000000; i++)
		if (p[i])
			ps.pb(i);
	vector<ll> qs;
	for (int i = 2; i <= 1000000; i++) if (p[i])
		for (ll j = i; j <= x; j *= i)
			if (x % (j + 1) == 0)
				qs.pb(j + 1);
	for (int d = 1; d <= 1000000; d++) if (x % d == 0) {
		ll y = x / d;
		bool ok = (y - 1 >= 2);
		for (int p: ps) if ((y - 1) % p == 0) ok = false;
		if (ok) qs.pb(y);
	}
	sort(qs.begin(), qs.end());
	qs.erase(unique(qs.begin(), qs.end()), qs.end());
	// for (int x: qs) cout << x << endl;
	map<ll, ll> mp;
	mp[x] = 1;
	for (ll q: qs) {
		map<ll, ll> _mp;
		for (ll_ll z: mp) {
			_mp[z.first] += z.second;
			if (z.first % q == 0) _mp[z.first / q] += z.second;
		}
		mp = _mp;
	}
	return mp[1];
}

int f(vector<int>& index, vector<int>& _index, ll x, ll y) {
	return y <= 1000000 ? index[y] : _index[x / y];
}

int main() {
	vector<bool> p(1000001, true);
	for (int i = 2; i <= 1000000; i++)
		if (p[i])
			for (int j = i * 2; j <= 1000000; j += i)
				p[j] = false;
	vector<int> ps;
	for (int i = 2; i <= 1000000; i++)
		if (p[i])
			ps.pb(i);
	ll x; cin >> x;
	vector<ll> ds;
	for (ll d = 1; d * d <= x; d++)
		if (x % d == 0) {
			ds.pb(d);
			if (d * d < x) ds.pb(x / d);
		}
	int N = ds.size();
	vector<int> index(1000001), _index(1000001);
	for (int i = 0; i < N; i++)
		if (ds[i] <= 1000000) index[ds[i]] = i;
		else _index[x / ds[i]] = i;
	vector<ll> dp(N);
	dp[f(index, _index, x, x)] = 1;
	for (int p: ps) {
		vector<ll> _dp = dp;
		for (ll q = p; q <= x; q *= p) if (x % (q + 1) == 0)
			for (ll d: ds) if (d % (q + 1) == 0)
				_dp[f(index, _index, x, d / (q + 1))] += dp[f(index, _index, x, d)];
		dp = _dp;
	}
	ll ans = dp[0];
	for (ll d: ds) {
		ll z = d - 1;
		if (z <= 1000000) continue;
		bool ok = true;
		for (int p: ps)
			if (z % p == 0) {
				ok = false;
				break;
			}
		if (ok) ans += dp[f(index, _index, x, d)];
	}
	cout << ans << endl;
}