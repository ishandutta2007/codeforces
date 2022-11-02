#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")

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
#include <numeric>

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

std::mt19937 rnd(time(0));

template<typename T>
bool minravno(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool maxravno(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

vector<vector<int>> g;
vector<bool> used;

int dfs(int v) {
	used[v] = true;
	int res = 1;
	for (auto u : g[v]) {
		if (!used[u])
			res += dfs(u);
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(n + 1, 0);
	g.assign(n + 1, {});
	used.assign(n + 1, false);
	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		cnt[u] ++;
		cnt[v] ++;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		if (cnt[i] < 2) {
			cout << "NO\n";
			return;
		}
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && dfs(i) % 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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