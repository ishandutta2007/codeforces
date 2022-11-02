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

const int MAXN = 2e5 + 10, LOG = 20;

vector<int> g[MAXN];
int p[MAXN], h[MAXN];
int up[LOG][MAXN];

void dfs(int v) {
	for (auto u : g[v]) {
		if (u == p[v])
			continue;
		h[u] = h[v] + 1;
		p[u] = v;
		dfs(u);
	}
}

int lca(int u, int v) {
	for (int k = LOG - 1; k >= 0; --k)
		if (h[up[k][u]] >= h[v])
			u = up[k][u];
	for (int k = LOG - 1; k >= 0; --k)
		if (h[up[k][v]] >= h[u])
			v = up[k][v];
	if (v == u)
		return v;
	for (int k = LOG - 1; k >= 0; --k) {
		if (up[k][v] != up[k][u])
			v = up[k][v], u = up[k][u];
	}
	return p[v];
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	p[1] = 1;
	dfs(1);
	for (int k = 0; k < LOG; ++k) {
		for (int v = 1; v <= n; ++v) {
			if (k == 0)
				up[k][v] = p[v];
			else
				up[k][v] = up[k - 1][up[k - 1][v]];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		vector<int> a(k);
		input(a);
		if (k == 1) {
			cout << "YES\n";
			continue;
		}
		int l = a[0];
		for (auto i : a)
			l = lca(l, i);
		set<int> s;
		for (auto i : a) {
			for (int k = LOG - 1; k >= 0; --k) {
				if (h[up[k][i]] > h[l])
					i = up[k][i];
			}
			s.insert(i);
		}
		s.erase(l);
		if (s.size() > 2) {
			cout << "NO\n";
			continue;
		}
		sort(all(a), [&](int u, int v) {
			return h[u] < h[v];
			});
		int u = *s.begin(), v = *s.rbegin();
		bool flag = true;
		for (auto i : a) {
			if (i == l)
				continue;
			if (lca(i, u) != u && lca(i, v) != v) {
				flag = false;
				break;
			}
			if (lca(i, u) == u)
				u = i;
			if (lca(i, v) == v)
				v = i;
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}