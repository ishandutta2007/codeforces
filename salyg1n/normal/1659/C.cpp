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
#include <fstream>
//#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long double ld;

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
//#define int ll
#define DEBUG

//std::mt19937 rnd(time(0));
std::mt19937 rnd(time(0));
using namespace std;


void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> x(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> x[i];
	vector<int> dp(n + 1, 0);
	int p = 0;
	int ans = 1e18;

	for (int i = 1; i <= n; ++i) {
		while (p + 1 < i && dp[p + 1] + (x[i] - x[p + 1]) * (a + b) < dp[p] + (x[i] - x[p]) * (a + b))
			p++;
		dp[i] = dp[p] + (x[i] - x[p]) * (a + b);
	}
	int sum = 0;
	for (int i = n; i >= 0; --i) {
		ans = min(ans, dp[i] + b * (sum - (x[i] * (n - i))));
		sum += x[i];
	}
	cout << ans << "\n";
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