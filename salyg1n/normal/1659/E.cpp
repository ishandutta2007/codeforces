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

const int MAXN = 1e5 + 10;

vector<int> g[30][MAXN];

int used[30][MAXN];
bool check[30][MAXN];
bool flag[MAXN];

void dfs(int v, int k, int num) {
	used[k][v] = num;
	if (flag[v])
		check[k][num] = true;
	for (auto u : g[k][v]) {
		if (!used[k][u])
			dfs(u, k, num);
	}
}

void solve(int u, int v) {
	for (int k = 0; k < 30; ++k) {
		if (used[k][u] == used[k][v]) {
			cout << 0 << "\n";
			return;
		}
	}
	for (int k = 1; k < 30; ++k) {
		if (check[k][used[k][u]]) {
			cout << "1\n";
			return;
		}
	}
	cout << "2\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w % 2 == 0) {
			flag[u] = flag[v] = true;
		}
		for (int k = 0; k < 30; ++k) {
			if (w & (1ll << k)) {
				g[k][v].push_back(u);
				g[k][u].push_back(v);
			}
		}
	}
	for (int k = 0; k < 30; ++k) {
		int num = 0;
		for (int i = 1; i <= n; ++i) {
			if (!used[k][i]) {
				num++;
				dfs(i, k, num);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		solve(u, v);
	}
	return 0;
}