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
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
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
	int n;
	cin >> n;
	ll minl = 1e18, minlc = 0, maxr = 0, maxrc = 0, maxlen = 0, maxlenc = 0;
	for (int i = 0; i < n; ++i) {
		ll l, r, c;
		cin >> l >> r >> c;
		if (r - l + 1 > maxlen) {
			maxlen = r - l + 1;
			maxlenc = c;
		}
		if (r - l + 1 == maxlen)
			maxlenc = min(maxlenc, c);
		if (l < minl) {
			minl = l;
			minlc = c;
		}
		if (l == minl)
			minlc = min(minlc, c);
		if (r > maxr) {
			maxr = r;
			maxrc = c;
		}
		if (r == maxr)
			maxrc = min(maxrc, c);
		if (maxr - minl + 1 > maxlen)
			cout << minlc + maxrc << "\n";
		else if (maxr - minl + 1 < maxlen)
			cout << maxlenc << "\n";
		else
			cout << min(minlc + maxrc, maxlenc) << "\n";
	}
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