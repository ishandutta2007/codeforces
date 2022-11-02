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

//#define ll long long
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

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		char c;
		cin >> n >> c;
		string s;
		cin >> s;
		s = c + s;
		vector<ll> a = {0};
		for (ll i = 1; i <= n; ++i) {
			if (s[i] == c)
				a.push_back(i);
		}
		if (a.size() == n + 1) {
			cout << "0\n";
			continue;
		}
		if (a.back() > n / 2) {
			cout << "1\n" << a.back() << "\n";
		}
		else {
			cout << "2\n" << n - 1 << " " << n << "\n";
		}
	}
	return 0;
}