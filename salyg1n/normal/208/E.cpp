#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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

#define int int_fast64_t

using namespace std;

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef double ld;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<pair<int, int>>> vvpi;
typedef tuple<int, int, int> ti;
typedef vector<tuple<int, int, int>> vti;
typedef set<int> si;
typedef set<pi> spi;
typedef multiset<int> msi;
typedef map<int, int> mii;
typedef unordered_set<int> usi;
typedef priority_queue<int> pqi;
typedef priority_queue<pair<int, int>> pqpi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef queue<int> qi;
typedef queue<pi> qpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define pq priority_queue

//#define x first
//#define y second
//#define DEBUG

std::mt19937 rnd(228);

template<typename T> bool minravno(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}
template<typename T> bool maxravno(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}
template<typename T> void input(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	for (; i <= j; ++i)
		std::cin >> a[i];
}
template<typename T> void print(const vector<T>& a, int i = 0, int j = -1, char c = ' ') {
	if (j == -1)
		j = a.size() - 1;
	for (; i <= j; ++i)
		std::cout << a[i] << c;
}
template<typename T> void prefsum(T a, T& p) {
	p.resize(a.size());
	partial_sum(all(a), p.begin());
}
template<typename T> struct ovec {
	vector<T> a;
	int n;
	ovec(int n_) {
		n = n_;
		a.resize(2 * n + 1);
	}
	T operator[](int i) {
		return a[i + n];
	}
};
template<typename T> T min(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	return *min_element(a.begin() + i, a.begin() + j + 1);
}
template<typename T> T max(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	return *max_element(a.begin() + i, a.begin() + j + 1);
}
template<typename T> T sum(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	int res = 0;
	for (; i <= j; ++i)
		res += a[i];
	return res;
}
template<typename T> void sort(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	sort(a.begin() + i, a.begin() + j + 1);
}
template<typename T> void rsort(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	sort(a.begin() + i, a.begin() + j + 1);
	reverse(a.begin() + i, a.begin() + j + 1);
}

const int MOD = 998244353, MAXN = 1e5 + 10;

vi g[MAXN];
int tin[MAXN], tout[MAXN], h[MAXN], dp[MAXN], p[MAXN];
int up[MAXN][20];
int timer = 0;
vpi q[MAXN];
int ans[MAXN];

void dfs(int v) {
	dp[v] = 1;
	tin[v] = ++timer;
	for (auto u : g[v]) {
		h[u] = h[v] + 1;
		dfs(u);
		dp[v] += dp[u];
	}
	tout[v] = ++timer;
}

int lca(int u, int v) {
	if (tin[u] <= tin[v] && tout[u] >= tout[v])
		return u;
	for (int k = 19; k >= 0; --k) {
		int nu = up[u][k];
		if (tin[nu] > tin[v] || tout[nu] < tout[v])
			u = nu;
	}
	return p[u];
}

void dfs2(int v, mii& m) {
	int mx = 0;
	for (auto u : g[v]) {
		maxravno(mx, dp[u]);
	}
	int tmp;
	for (auto u : g[v]) {
		if (dp[u] == mx) {
			dfs2(u, m);
			tmp = u;
			break;
		}
	}
	for (auto u : g[v]) {
		if (u == tmp)
			continue;
		mii mp;
		dfs2(u, mp);
		for (auto [fs, sc] : mp)
			m[fs] += sc;
	}
	m[h[v]]++;
	for (auto [x, id] : q[v])
		ans[id] = m[h[v] + x] - 1;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		if (p[i] == 0)
			p[i] = i;
		else
			g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i] == i)
			dfs(i);
	}
	for (int k = 0; k < 20; ++k) {
		for (int v = 1; v <= n; ++v) {
			if (k == 0)
				up[v][k] = p[v];
			else
				up[v][k] = up[up[v][k - 1]][k - 1];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int v, x;
		cin >> v >> x;
		if (x > h[v])
			continue;
		int y = x;
		for (int k = 19; k >= 0; --k) {
			if ((1 << k) <= x) {
				x -= (1 << k);
				v = up[v][k];
			}
		}
		q[v].push_back({ y, i });
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i] == i) {
			mii tmp;
			dfs2(i, tmp);
		}
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << ' ';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	return 0;
}