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
	vector<int> a(n), b(n);
	input(a);
	input(b);
	ll sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i] + b[i];
	bitset<10001> bs;
	bs[0] = 1;
	for (int i = 0; i < n; ++i)
		bs = (bs << a[i]) | (bs << b[i]);
	ll mx = 0;
	for (int i = sum / 2; i >= 0; --i) {
		if (bs[i]) {
			mx = i;
			break;
		}
	}
	ll ans = mx * mx + (sum - mx) * (sum - mx);
	for (int i = 0; i < n; ++i) {
		ans += a[i] * a[i] * (n - 2);
		ans += b[i] * b[i] * (n - 2);
	}
	cout << ans << "\n";
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