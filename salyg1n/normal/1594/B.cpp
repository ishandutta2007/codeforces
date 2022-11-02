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
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//#define int long long
//#define DEBUG

using namespace std;

ll mod = 1e9 + 7;

ll power(ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		ll tmp = power(a, n / 2);
		return tmp * tmp % mod;
	}
	return power(a, n - 1) * a % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll res = 0;
		ll i = 32;
		while (k) {
			if ((1ll << i) <= k) {
				k -= (1ll << i);
				res += power(n, i);
				res %= mod;
			}
			i--;
		}
		cout << res << "\n";
	}
	return 0;
}