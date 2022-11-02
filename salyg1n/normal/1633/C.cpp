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

bool check(ll hc, ll dc, ll hm, ll dm) {
	ll k1 = (hm + dc - 1) / dc;
	ll k2 = (hc + dm - 1) / dm;
	if (k1 <= k2)
		return true;
	return false;
}

void solve() {
	ll hc, dc, hm, dm, k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	for (int i = 0; i <= k; ++i) {
		if (check(hc + a * i, dc + w * (k - i), hm, dm)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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