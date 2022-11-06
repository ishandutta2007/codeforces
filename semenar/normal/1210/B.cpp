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
using vb = vector<bool>;

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

	int n;
	cin >> n;

	time_t start = clock();

	vl a(n);
	vi b(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	//for (int i = 0; i < n; i++) a[i] = rng();
	//for (int i = 0; i < n; i++) b[i] = rng() % MOD;

	ll ans = 0;
	bool changed = true;
	vb taken(n, true);

	while (changed) {
		ll mask = 0;
		changed = false;
		for (int i = 0; i < n; i++) {
			if (!taken[i]) continue;
			bool bad = true;
			for (int j = 0; j < n && bad; j++) {
				if (i != j && taken[j] && (a[i] & a[j]) == a[i]) bad = false;
			}
			if (bad) {
				taken[i] = false;
				changed = true;
			}
		}
	}

	for (int i = 0; i < n; i++) if (taken[i]) ans += b[i];

	cout << ans << endl;

	//cout << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

	return 0;
}