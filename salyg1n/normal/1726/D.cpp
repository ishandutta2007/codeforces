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
#include <complex>

#define int int_fast32_t

using namespace std;

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef double ld;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
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

const int MOD = 998244353;

int power(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		int tmp = power(a, n / 2);
		return tmp * tmp % MOD;
	}
	return power(a, n - 1) * a % MOD;
}

vvpi g;
vb used;
vector<ti> a;
vi h, p;

void dfs(int v) {
	used[v] = true;
	for (auto [u, id] : g[v]) {
		if (!used[u]) {
			h[u] = h[v] + 1;
			p[u] = v;
			dfs(u);
		}
		else if (u != p[v] && h[v] > h[u])
			a.push_back({ v, u, id });
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	g.assign(n + 1, {});
	used.assign(n + 1, false);
	h.assign(n + 1, 0);
	p.assign(n + 1, 0);
	a.clear();
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		g[u].push_back({ v, i });
		g[v].push_back({ u, i });
	}
	dfs(1);
	vi ans(m, 1);
	vi tmp;
	for (auto [u, v, i] : a) {
		ans[i] = 0;
		tmp.push_back(u);
		tmp.push_back(v);
	}
	if (a.size() < 3) {
		for (int i = 0; i < m; ++i)
			cout << ans[i];
		cout << "\n";
		return;
	}
	sort(tmp);
	if (tmp[0] == tmp[1] && tmp[2] == tmp[3] && tmp[4] == tmp[5]) {
		int u = tmp[0], v = tmp[2], k = tmp[4];
		if (h[u] > h[v])
			swap(u, v);
		if (h[k] > h[v])
			swap(k, v);
		if (h[k] > h[u])
			swap(k, u);
		int j = v;
		while (p[j] && p[j] != u)
			j = p[j];
		int uv, uj;
		for (auto [uu, id] : g[u]) {
			if (uu == v)
				uv = id;
			if (uu == j)
				uj = id;
		}
		swap(ans[uv], ans[uj]);
	}
	for (int i = 0; i < m; ++i)
		cout << ans[i];
	cout << "\n";
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