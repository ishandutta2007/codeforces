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
	vector<int> a(n);
	input(a);
	if (n == 3) {
		if (a[1] % 2 == 0) {
			cout << a[1] / 2 << "\n";
		}
		else
			cout << "-1\n";
		return;
	}
	set<int> s = { 0, n - 1 };
	for (int i = 1; i < n - 1; ++i)
		if (a[i] % 2)
			s.insert(i);
	int ans = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 1; i < n - 1; ++i) {
			while (a[i] >= 2) {
				flag = true;
				auto l = --s.lb(i), r = s.lb(i);
				int l_ = *l, r_ = *r;
				if (l_ == 0 && r_ == n - 1) {
					a[0] += a[i] / 2;
					a[n - 1] += a[i] / 2;
					ans += a[i] / 2;
					a[i] -= a[i] / 2 * 2;
				}
				else {
					ans++;
					a[l_]++;
					a[r_]++;
					a[i] -= 2;
				}
				s.erase(l_);
				s.erase(r_);
				s.insert(0);
				s.insert(n - 1);
			}
		}
	}
	bool check = true;
	for (int i = 1; i < n - 1; ++i)
		if (a[i])
			check = false;
	if (check)
		cout << ans << "\n";
	else
		cout << "-1\n";
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