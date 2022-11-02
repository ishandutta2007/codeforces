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

const int MOD = 998244353, MAX = 1e6 + 1;

int power(int a, int n) {
	if (!n)
		return 1;
	if (n % 2 == 0) {
		int tmp = power(a, n / 2);
		return tmp * tmp % MOD;
	}
	return power(a, n - 1) * a % MOD;
}

const int MAXN = 1e5 + 10;

int tmn[4 * MAXN], tcn[4 * MAXN], tgcd[4 * MAXN];

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

void build(vi& a, int v, int tl, int tr) {
	if (tr - tl == 1) {
		tmn[v] = tgcd[v] = a[tl];
		tcn[v] = 1;
	}
	else {
		int m = (tr + tl) / 2;
		build(a, v * 2, tl, m);
		build(a, v * 2 + 1, m, tr);
		tmn[v] = min(tmn[v * 2], tmn[v * 2 + 1]);
		if (tmn[v] == tmn[v * 2])
			tcn[v] += tcn[v * 2];
		if (tmn[v] == tmn[v * 2 + 1])
			tcn[v] += tcn[v * 2 + 1];
		tgcd[v] = gcd(tgcd[v * 2], tgcd[v * 2 + 1]);
	}
}

ti get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return { 1e18, 0, 0 };
	if (l <= tl && r >= tr)
		return { tmn[v], tcn[v], tgcd[v] };
	int m = (tr + tl) / 2;
	auto[mn1, cn1, gcd1] = get(v * 2, tl, m, l, r);
	auto[mn2, cn2, gcd2] = get(v * 2 + 1, m, tr, l, r);
	int mn, cn = 0, gc;
	mn = min(mn1, mn2);
	if (mn == mn1)
		cn += cn1;
	if (mn == mn2)
		cn += cn2;
	gc = gcd(gcd1, gcd2);
	return { mn,cn,gc };
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	input(a);
	build(a, 1, 0, n);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		auto [mn, cnt, gcd] = get(1, 0, n, l - 1, r);
		if (mn == gcd)
			cout << r - l + 1 - cnt;
		else
			cout << r - l + 1;
		cout << '\n';
	}
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