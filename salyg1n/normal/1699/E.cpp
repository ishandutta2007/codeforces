#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")

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
#include <numeric>

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

#define int int_fast32_t
//#define DEBUG

std::mt19937 rnd(time(0));

template<typename T>
bool minravno(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool maxravno(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	input(a);
	vector<int> dp(m + 1, m), cnt(m + 1, 0);
	vector<bool> used(m + 1, false);
	for (auto i : a)
		used[i] = true;
	for (int i = 1; i <= m; ++i)
		cnt[m] += used[i];
	int ans = 1e9;
	int j = m;
	int mn = 1e9;
	for (auto i : a)
		minravno(mn, i);
	for (int i = m; i >= 1; --i) {
		if (used[i])
			cnt[dp[i]]--;
		dp[i] = i;
		if (used[i])
			cnt[dp[i]]++;
		for (int j = i * 2; j <= m; j += i) {
			if (used[j])
				cnt[dp[j]]--;
			dp[j] = min(dp[j], dp[j / i]);
			if (used[j])
				cnt[dp[j]]++;
		}
		while (!cnt[j])
			j--;
		if (i <= mn)
			ans = min(ans, j - i);
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}