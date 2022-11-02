//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define int long long
//#define DEBUG

using namespace std;

const ll MAXN = 2e5 + 1, mod = 998244353;

ll fact[MAXN];

ll power(ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		ll tmp = power(a, n / 2);
		return tmp * tmp % mod;
	}
	return power(a, n - 1) * a % mod;
}

ll Div(ll a, ll b) {
	return a * power(b, mod - 2) % mod;
}

ll cnk(ll n, ll k) {
	if (n == k)
		return 1;
	return Div(fact[n], fact[k] * fact[n - k] % mod);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[1] = 1;
	for (ll i = 2; i < MAXN; ++i)
		fact[i] = fact[i - 1] * i % mod;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		input(a);
		sort(all(a));
		int cntmx = 0, cnt = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == a.back())
				cntmx++;
			if (a[i] == a.back() - 1)
				cnt++;
		}
		if (cntmx) {
			cout << fact[n] << "\n";
			continue;
		}
		if (!cnt) {
			cout << 0 << "\n";
			continue;
		}
		ll ans = ((fact[n] - fact[n - 1]) % mod + mod) % mod;
		for (int i = cnt; i < n - 1; ++i) {
			ans -= (cnk(i, cnt) * fact[cnt] % mod) * fact[n - cnt - 1] % mod;
			ans = ((ans % mod) + mod) % mod;
		}
		cout << ans << "\n";
	}
	return 0;
}