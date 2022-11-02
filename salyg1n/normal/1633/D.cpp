//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
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
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

#define int int_fast64_t
#define ll int_fast64_t
//#define DEBUG

using namespace std;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector <ll> b(n + 1, 0), c(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	vector<ll> a(n + 1, 0);
	ll sum = 0;
	vector<ll> dp1(1e3 + 1, 1e9);
	dp1[1] = 0;
	for (int i = 1; i < (int)1e3; ++i) {
		for (int x = 1; x <= i; ++x) {
			if (i + i / x <= (int)1e3)
				dp1[i + i / x] = min(dp1[i + i / x], dp1[i] + 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = dp1[b[i]];
		sum += a[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
	for (int i = 0; i <= sum; ++i)
		dp[0][i] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i][0] = (a[i] == 0 ? dp[i-1][0] + c[i] : dp[i-1][0]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= sum; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (a[i] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + c[i]);
		}
	}
	ll mx = 0;
	for (int i = 0; i <= min(k, sum); ++i)
		mx = max(mx, dp[n][i]);
	cout << mx << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}