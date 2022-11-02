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
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//#define int long long
//#define DEBUG

using namespace std;

vector<int> in, a;
vector<int> check;
int xr = 0;
vector<vector<int>> g;

void dfs(int v, int p = -1) {
	in[v] = a[v];
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
			in[v] ^= in[u];
		}
	}
}

void dfs2(int v, int p = -1) {
	check[v] = 0;
	for (auto u : g[v]) {
		if (u != p) {
			dfs2(u, v);
			check[v] += check[u];
			if (in[u] == xr)
				check[v]++;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		in.clear();
		a.clear();
		check.clear();
		g.clear();
		in.resize(n + 1);
		a.resize(n + 1);
		check.resize(n + 1);
		g.resize(n + 1);
		xr = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			xr ^= a[i];
		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (xr && k == 2) {
			cout << "NO\n";
			continue;
		}
		if (xr) {
			dfs(1);
			dfs2(1);
			string ans = "NO\n";
			for (int i = 2; i <= n; ++i) {
				if ((check[i] && in[i] == 0))
					ans = "YES\n";
			}
			if (check[1] > 1)
				ans = "YES\n";
			cout << ans;
		}
		else {
			cout << "YES\n";
		}
	}
	return 0;
}