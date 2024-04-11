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
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<int> ans(3 * n, 1);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (ans[i] == 0) {
			ans[a[i] + i] = 0;
			continue;
		}
		if (sum == 0) {
			if (a[i]) {
				ans[a[i] + 1] = 0;
				ans[i] = 1;
				sum = 1;
			}
			else
				ans[i] = 0;
			continue;
		}
		ans[a[i] + 1] = 0;
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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