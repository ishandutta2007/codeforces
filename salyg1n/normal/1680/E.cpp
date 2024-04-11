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

typedef int_fast64_t ll;
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
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<char>> a(2, vector<char>(n + 1));
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	vector<vector<int>> dp(n + 1, vector<int>(2));
	dp[0][0] = dp[0][1] = 0;
	bool founded = false;
	for (int i = 1; i <= n; ++i) {
		int cnt = int(a[0][i] == '*') + int(a[1][i] == '*');
		if (!cnt) {
			if (founded)
				dp[i][0] = dp[i - 1][0] + 1, dp[i][1] = dp[i - 1][1] + 1;
			else
				dp[i][0] = dp[i][1] = 0;
		}
		else if (cnt == 1) {
			if (a[0][i] == '*') {
				if (founded) {
					dp[i][0] = dp[i - 1][0] + 1;
					dp[i][1] = min(dp[i][0] + 1, dp[i - 1][1] + 2);
				}
				else
					dp[i][0] = 0, dp[i][1] = 1;
			}
			else {
				if (founded) {
					dp[i][1] = dp[i - 1][1] + 1;
					dp[i][0] = min(dp[i][1] + 1, dp[i - 1][0] + 2);
				}
				else
					dp[i][0] = 1, dp[i][1] = 0;
			}
			founded = true;
		}
		else {
			if (founded)
				dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 2;
			else
				dp[i][0] = dp[i][1] = 1;
			founded = true;
		}
	}
	for (int i = n; i >= 1; --i) {
		int cnt = int(a[0][i] == '*') + int(a[1][i] == '*');
		if (cnt) {
			cout << min(dp[i][0], dp[i][1]) << "\n";
			return;
		}
	}
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