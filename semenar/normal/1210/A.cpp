#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <random>
#include <map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

#define X first
#define Y second

using namespace std;

mt19937 rng(time(NULL));

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

const ll MOD = 1000000007;

ll sqr(ll a) {
	return a * a;
}

ll powmod(ll a, ll x, ll p = MOD) {
	if (x <= 0) return 1;
	if (x % 2 == 0) return sqr(powmod(a, x >> 1, p)) % p;
	else return (a * powmod(a, x - 1, p)) % p;
}

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}


int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pii> e(m);

	for (int i = 0; i < m; i++) {
		cin >> e[i].X >> e[i].Y;
		e[i].X--, e[i].Y--;
	}

	ll lim = powmod(6, n);

	int ans = 0;

	for (ll i = 0; i < lim; i++) {
		ll mask = i;
		vi num(n);
		for (int k = 0; k < n; k++) {
			num[k] = mask % 6;
			mask /= 6;
		}

		set<pii> domino;
		for (auto el : e) {
			domino.insert(mp(min(num[el.X], num[el.Y]), max(num[el.X], num[el.Y])));
		}

		ans = max(ans, sz(domino));
	}

	cout << ans << endl;

	return 0;
}