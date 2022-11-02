//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
//#define int ll
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

const int MAX = 1e6 + 1;

ll m[MAX + 1];
ll mx[MAX + 1];

void solve() {
	int n, C;
	cin >> n >> C;
	for (int i = 0; i < n; ++i) {
		ll c, d, h;
		cin >> c >> d >> h;
		m[c] = max(m[c], d * h);
	}
	mx[0] = 0;
	for (int i = 1; i < MAX; ++i) {
		mx[i] = mx[i - 1];
		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) {
				ll x = i / j;
				mx[i] = max(mx[i], x * m[j]);
				mx[i] = max(mx[i], (ll)j * m[x]);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		ll D, H;
		cin >> D >> H;
		int l = 0, r = C + 1;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (mx[m] > D * H)
				r = m;
			else
				l = m;
		}
		if (r == C + 1)
			cout << -1 << " ";
		else
			cout << r << " ";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}