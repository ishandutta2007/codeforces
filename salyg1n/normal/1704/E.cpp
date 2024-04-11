/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
*/
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
#include <complex>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef double ld;
typedef std::complex<ld> cd;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " "
#define input(a) for (auto& _ : a) cin >> _
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

std::mt19937 rnd(55);

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

const int MOD = 998244353;

void dfs(int v, vector<vector<int>>& g, vector<bool>& used, vector<int>& topsort) {
	used[v] = true;
	for (auto u : g[v]) {
		if (!used[u])
			dfs(u, g, used, topsort);
	}
	topsort.push_back(v);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	vector<bool> used(n + 1, false);
	vector<int> topsort;
	for (int i = 1; i <= n; ++i)
		if (!used[i])
			dfs(i, g, used, topsort);
	reverse(all(topsort));
	vector<vector<pair<int, int>>> b(n + 1);
	int ans = 0;
	for (auto v : topsort) {
		b[v].push_back({ 0, 1 });
		b[v].push_back({ a[v], -1 });
		b[v].push_back({ (int)1e18, (int)0 });
		sort(all(b[v]));
		int last = 0, sum = 0, now = 0, prev = 0;
		vector<pair<int, int>> tmp;
		for (auto [i, x] : b[v]) {
			int t = i - last;
			sum += (i - prev) * now;
			prev = i;
			if (sum < t) {
				if (sum) {
					tmp.push_back({ last + 1, last + sum });
				}
				last = i;
				sum = 0;
			}
			now += x;
		}
		if (v == topsort.back() && tmp.size()) {
			ans = tmp.back().second;
		}
		for (auto u : g[v]) {
			int cnt = 0;
			for (auto [l, r] : tmp) {
				if (r <= n) {
					b[u].push_back({ l, 1 });
					b[u].push_back({ r + 1, -1 });
				}
				else {
					if (l <= n) {
						b[u].push_back({ l, 1 });
						b[u].push_back({ n + 1, -1 });
					}
					cnt += (r - max(l, n + 1) + 1);
					cnt %= MOD;
				}
			}
			b[u].push_back({ n + 1, cnt });
			b[u].push_back({ n + 2, -cnt });
		}
	}
	cout << ans % MOD << "\n";
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