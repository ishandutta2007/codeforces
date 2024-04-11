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

//#define int int_fast64_t
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	string s, s1;
	cin >> s;
	for (int i = 0; i < n * m; ++i)
		s1 += '0';
	s = s1 + s;
	vector<int> r(2 * n * m + 1, 0), dp(2 * n * m, 0);
	for (int i = 2 * n * m - 1; i >= 0; --i) {
		if (s[i] == '1')
			r[i] = 0;
		else
			r[i] = r[i + 1] + 1;
	}
	for (int i = m - 1; i < 2 * n * m; ++i) {
		if (i >= m)
			dp[i] = dp[i - m];
		dp[i] += (r[i - m + 1] >= m);
	}
	vector<int> a(m, 0);
	int sum = 0;
	for (int i = n * m; i < 2 * n * m; ++i) {
		int j = i % m;
		if (!a[j] && s[i] == '1') {
			sum++;
			a[j]++;
		}
		cout << (n - (dp[i] - dp[i - n * m])) + sum << " ";
	}
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}