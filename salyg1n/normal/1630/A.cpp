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

//#define int long long
//#define DEBUG

using namespace std;

void solve() {
	ll n, k;
	cin >> n >> k;
	ll st = 64 - __builtin_clzll(n - 1);
	if (k == n - 1) {
		if (n == 4) {
			cout << -1 << "\n";
			return;
		}
		int ans = 0;
		cout << n - 1 << " " << n - 2 << "\n";
		ans += (n - 1) & (n - 2);
		cout << "3 1\n";
		ans += 3 & 1;
		cout << "0 " << n - 1 - 3 << "\n";
		for (int i = 0; i < n / 2; ++i) {
			if (i == n - 1 || i == 0 || i == n - 2 || i == 3 || i == 1 || i == n - 4)
				continue;
			cout << i << " " << n - 1 - i << "\n";
			ans += i & (n - 1 - i);
		}
		return;
	}
	if (k == 0) {
		for (int i = 0; i < n / 2; ++i) {
			cout << i << " " << n - 1 - i << "\n";
		}
		return;
	}
	cout << k << " " << n - 1 << "\n";
	cout << n - 1 - k << " " << 0 << "\n";
	for (int i = 0; i < n / 2; ++i) {
		if (i == k || i == 0 || i == n - 1 - k || i == n - 1)
			continue;
		cout << i << " " << n - 1 - i << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}