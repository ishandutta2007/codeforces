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

template<typename T>
void input(T& a, int i = 0) {
	for (; i < a.size(); ++i)
		std::cin >> a[i];
}

template<typename T>
void print(const T& a, char c = ' ', int i = 0) {
	for (; i < a.size(); ++i)
		std::cout << a[i] << c;
}

struct DO {
	int n;
	vi t;
	DO(int n_) {
		n = n_;
		t.resize(4 * n + 1, 1e18);
	 }

	void build(vi& a, int v, int tl, int tr) {
		if (tr - tl == 1)
			t[v] = a[tl];
		else {
			int m = (tr + tl) / 2;
			build(a, v * 2, tl, m);
			build(a, v * 2 + 1, m, tr);
			t[v] = min(t[v * 2], t[v * 2 + 1]);
		}
	}

	int find(int v, int tl, int tr, int l, int r, int x) {
		if (t[v] > x)
			return n + 1;
		if (r <= tl || tr <= l)
			return n + 1;
		if (tr - tl == 1)
			return tl;
		int m = (tr + tl) / 2;
		int res = find(v * 2, tl, m, l, r, x);
		if (res != n + 1)
			return res;
		return find(v * 2 + 1, m, tr, l,r ,x);
	}
};

void solve() {
	int n, s;
	cin >> n >> s;
	vi a(n + 1);
	input(a, 1);
	vi p(n + 1);
	for (int i = 1; i <= n; ++i)
		p[i] = p[i - 1] + a[i];
	DO tree(n);
	tree.build(p, 1, 1, n + 1);
	int l = 0, r = -1;
	for (int i = 0; i < n; ++i) {
		int j = tree.find(1, 1, n + 1, i + 1, n + 1, p[i] - s - 1);
		if (j - 1 - i > r - l + 1)
			l = i + 1, r = j - 1;
	}
	if (!l)
		cout << "-1\n";
	else
		cout << l << " " << r << "\n";
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