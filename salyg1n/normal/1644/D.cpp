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
#include <memory>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

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

const ll mod = 998244353;

void solve() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<pair<int, int>> a = { {0, 0} };
	umap<int, int> b, c;
	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		a.push_back({ x, y });
		b[x] = i, c[y] = i;
	}
	int tc = 1e9, tb = 1e9;
	for (auto [ft, sc] : b)
		tb = min(tb, sc);
	for (auto [ft, sc] : c)
		tc = min(tc, sc);

	if (b.size() < n)
		tb = 0;
	if (c.size() < m)
		tc = 0;
	ll ans = 1;
	for (int i = 1; i <= q; ++i) {
		auto [x, y] = a[i];
		bool needb = true, needc = true;
		needb &= (b[x] == i);
		needb &= (tc <= i);
		needc &= (c[y] == i);
		needc &= (tb <= i);
		if (needb || needc)
			ans *= k;
		ans %= mod;
	}
	cout << ans << "\n";
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