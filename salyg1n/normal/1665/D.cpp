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

#define int int_fast64_t
//#define int ll
#define DEBUG

//std::mt19937 rnd(time(0));
std::mt19937 rnd(time(0));
using namespace std;

void solve() {
	int x = 0;
	for (int i = 0; i < 30; ++i) {
		int b = (1ll << (i + 1)) - x - (1ll << i);
		int a = b + (1ll << (i + 1));
		if (b == 0) {
			b += (1ll << (i + 1));
			a += (1ll << (i + 1));
		}
		if (a > (int)2e9)
			break;
		cout << "? " << a << " " << b << endl;
		int y;
		cin >> y;
		if (y == (1ll << (i + 1)))
			x += (1ll << i);
	}
	cout << "! " << x << endl;
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