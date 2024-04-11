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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	input(a);
	if (k >= n) {
		int ans = (k - n) * n + n * (n - 1) / 2;
		for (auto i : a)
			ans += i;
		cout << ans << "\n";
		return;
	}
	vector<int> p(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] + a[i - 1];
	int ans = 0;
	for (int i = k; i <= n; ++i)
		ans = max(ans, (k - 1) * k / 2 + p[i] - p[i - k]);
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