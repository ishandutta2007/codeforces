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
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	input(a);
	auto b = a;
	sort(all(b));
	int c = (n + k + 1) / 2;
	int mn = 1e9, x = 0, y = 1e9;
	for (int i = 0; i < n - c + 1; ++i) {
		if (mn > b[i + c - 1] - b[i])
			mn = b[i + c - 1] - b[i], x = b[i], y = b[i + c - 1];
	}
	cout << x << " " << y << "\n";
	int nows = 0, now = 0, cnt = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] >= x && a[i] <= y)
			now++;
		if (now > (i - nows + 1) / 2 && cnt < k - 1) {
			cout << nows + 1 << " " << i + 1 << "\n";
			nows = i + 1;
			now = 0;
			cnt++;
		}
	}
	cout << nows + 1 << " " << n << "\n";
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