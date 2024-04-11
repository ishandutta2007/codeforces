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

#define int long long
//#define DEBUG

using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << "3 2 1\n1 3 2\n3 1 2\n";
		return;
	}
	vector<int> a;
	for (int i = n; i >= 1; --i)
		a.push_back(i);
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j)
			cout << a[j] << " ";
		for (int j = 0; j < i; ++j)
			cout << a[j] << " ";
		cout << "\n";
	}
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