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

#define endl '\n'

#define int int_fast64_t
//#define int ll
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int& e : arr)
		cin >> e;
	sort(all(arr));

	unordered_map<int, int> cnt;
	for (int i : arr)
		++cnt[i];

	if (cnt[0] != 0 && cnt[1] != 0) {
		cout << "NO" << endl;
		return;
	}

	if (cnt[1] == 0 || cnt[1] == n) {
		cout << "YES" << endl;
		return;
	}

	for (int i = 1; i < n; ++i) {
		if (arr[i] - arr[i - 1]  == 1) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	
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