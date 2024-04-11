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
//#define DEBUG

//std::mt19937 rnd(time(0));
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	input(a);
	int ans = 1e18;
	for (int i = 0; i < n; ++i) {
		int last = 0;
		int cur = 0;
		for (int j = i - 1; j >= 0; --j) {
			int op = last/ a[j] + 1;
			cur += op;
			last = a[j] * op;
		}
		last = 0;
		for (int j = i + 1; j < n; ++j) {
			int op = last / a[j] + 1;
			cur += op;
			last = a[j] * op;
		}
		ans = min(ans, cur);
	}
	cout << ans; 
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