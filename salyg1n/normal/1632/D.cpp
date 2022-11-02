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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

const int MAXN = 2e5 + 10;

int t[MAXN * 4];

void build(vector<int>& a, int v, int tl, int tr) {
	if (tr - tl == 1)
		t[v] = a[tl];
	else {
		int m = (tr + tl) / 2;
		build(a, v * 2, tl, m);
		build(a, v * 2 + 1, m, tr);
		t[v] = gcd(t[v * 2], t[v * 2 + 1]);
	}
}

int get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && r >= tr)
		return t[v];
	int m = (tl + tr) / 2;
	return gcd(get(v * 2, tl, m, l, r), get(v * 2 + 1, m, tr, l, r));
}

void solve() {

	int n;
	cin >> n;
	vector<int> a(n + 1, 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	a.push_back(1e9 + 7);
	build(a, 1, 0, n + 2);
	vector<int> dp(n + 1), gc(n + 1);
	dp[1] = 1;
	gc[1] = a[1];
	while (gc[1] >= dp[1])
		gc[1] = gcd(gc[1], a[++dp[1]]);
	
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1];
		gc[i] = get(1, 0, n + 2, i, dp[i] + 1);
		while (gc[i] >= dp[i] - i + 1)
			gc[i] = gcd(gc[i], a[++dp[i]]);
	}
	int last = 0;
	vector<bool> flag(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		if (get(1, 0, n + 2, i, dp[i]) == dp[i] - i && last < i) {
			last = dp[i] - 1;
			flag[last] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (flag[i])
			ans++;
		cout << ans << " ";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t
	while (t--)
		solve();
	return 0;
}