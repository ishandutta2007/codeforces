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
void print(const T& a, int i = 0, char c = ' ') {
	for (; i < a.size(); ++i)
		std::cout << a[i] << c;
}

template<typename T>
void prefsum(T a, T& p) {
	p.resize(a.size());
	partial_sum(all(a), p.begin());
}

void solve() {
	int n;
	cin >> n;
	mii m;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		m[x]++;
	}
	vi a = {0};
	for (auto [x, y] : m)
		a.push_back(y);
	vi p;
	prefsum(a, p);
	n = a.size() - 1;
	vi dp1(n + 1, 1e18), dp2(n + 1, 1e18), dp3(n + 1, 1e18);
	dp1[0] = 1;
	dp2[0] = 2;
	dp3[0] = 3;
	for (int i = 1; i <= n; ++i) {
		int l = -1, r = 20;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if ((1 << m) < p[i])
				l = m;
			else
				r = m;
		}
		dp1[i] = (1 << r) - p[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int k = 18; k >= 0; --k) {
			int l = -1, r = i;
			while (r - l > 1) {
				int m = (r + l) / 2;
				if (p[i] - p[m] <= (1 << k))
					r = m;
				else
					l = m;
			}
			minravno(dp2[i], dp1[r] + (1 << k) - (p[i] - p[r]));
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int k = 18; k >= 0; --k) {
			int l = -1, r = i;
			while (r - l > 1) {
				int m = (r + l) / 2;
				if (p[i] - p[m] <= (1 << k))
					r = m;
				else
					l = m;
			}
			minravno(dp3[i], dp2[r] + (1 << k) - (p[i] - p[r]));
		}
	}
	cout << dp3[n] << "\n";
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