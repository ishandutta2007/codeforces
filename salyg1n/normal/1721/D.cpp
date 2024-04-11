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

void solve() {
	int n;
	cin >> n;
	vvi a(1, vi(n)), b(1, vi(n));
	input(a[0]);
	input(b[0]);
	int ans = 0;
	for (int k = 29; k >= 0; --k) {
		vvi na, nb;
		bool flag = true;
		for (int i = 0; i < a.size(); ++i) {
			auto c = a[i], d = b[i];
			vi c1, c2, d1, d2;
			for (auto j : c)
				if ((j >> k) & 1)
					c1.push_back(j);
				else
					c2.push_back(j);
			for (auto j : d)
				if ((j >> k) & 1)
					d2.push_back(j);
				else
					d1.push_back(j);
			if (c1.size() != d1.size())
				flag = false;
			else {
				if (c1.size())
					na.push_back(c1);
				if (c2.size())
					na.push_back(c2);
				if (d1.size())
					nb.push_back(d1);
				if (d2.size())
					nb.push_back(d2);
			}
		}
		if (flag) {
			ans += (1 << k);
			a = na;
			b = nb;
		}
	}
	cout << ans << "\n";
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