//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
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
#define vll __int128
//#define x first
//#define y second

//#define int long long
//#define DEBUG

using namespace std;

void dfs(int v, vector<int> & used, vector<vector<int>> & g) {
	for (auto u : g[v]) {
		if (!used[u]) {
			used[u] = 3 - used[v];
			dfs(u, used, g);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> used(n + 1, 0);
	used[1] = 1;
	dfs(1, used, g);
	int k;
	for (k = 0; (1 << k) <= n; ++k);
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i] == 1)
			cnt1++;
		else
			cnt2++;
	}
	int b = (1 << k) - 1 - n;
	b = (1 << (k - 1)) - b;
	vector<int> ans(n + 1, 0);
	if (cnt1 >= b) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!b)
				break;
			if (used[i] != 1)
				continue;
			cnt++;
			ans[i] = n - cnt + 1;
			cnt1--;
			b--;
		}
	}
	else {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!b)
				break;
			if (used[i] != 2)
				continue;
			cnt++;
			ans[i] = n - cnt + 1;
			cnt2--;
			b--;
		}
	}
	int tmp = cnt1;
	for (int i = 19; i >= 0; --i) {
		if (tmp >= (1 << i)) {
			int now = (1 << i);
			for (int j = 1; j <= n; ++j) {
				if (now == (1 << (i + 1)))
					break;
				if (used[j] == 1 && !ans[j])
					ans[j] = now++;
			}
			tmp -= (1 << i);
		}
	}
	tmp = cnt2;
	for (int i = 19; i >= 0; --i) {
		if (tmp >= (1 << i)) {
			int now = (1 << i);
			for (int j = 1; j <= n; ++j) {
				if (now == (1 << (i + 1)))
					break;
				if (used[j] == 2 && !ans[j])
					ans[j] = now++;
			}
			tmp -= (1 << i);
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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