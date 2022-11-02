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

template<typename T> void input(T& a, int i = 0) {
	for (; i < a.size(); ++i)
		std::cin >> a[i];
}

template<typename T> void print(const vector<T>& a, int i = 0, char c = ' ') {
	for (; i < a.size(); ++i)
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

template<typename T> T max(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size();
	return *max_element(a.begin() + i, a.begin() + j);
}

void solve() {	
	int n, m, k1;
	cin >> n >> m >> k1;
	int k2 = n * m / 2 - k1;
	if (n % 2 == 0 && m % 2 == 0) {
		if (k1 % 2 || k2 % 2) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		vvc a(n, vc(m));
		for (int i = 0; i + 1 < n; i += 2) {
			for (int j = 0; j + 1 < m; j += 2) {
				if (k1) {
					k1 -= 2;
					if ((j / 2) % 2 == 0) {
						a[i][j] = a[i][j + 1] = 'a';
						a[i + 1][j] = a[i + 1][j + 1] = 'b';
					}
					else {
						a[i][j] = a[i][j + 1] = 'b';
						a[i + 1][j] = a[i + 1][j + 1] = 'a';
					}
				}
				else {
					if ((i / 2) % 2 == 0) {
						a[i][j] = a[i + 1][j] = 'c';
						a[i][j + 1] = a[i + 1][j + 1] = 'd';
					}
					else {
						a[i][j] = a[i + 1][j] = 'd';
						a[i][j + 1] = a[i + 1][j + 1] = 'c';
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
	else {
		vvc a(n, vc(m));
		if (n % 2) {
			for (int i = 0; i < m; ++i)
				a[n - 1][i] = (i % 4 >= 2 ? 'y' : 'x');
			k1 -= m / 2;
		}
		else {
			for (int i = 0; i < n; ++i)
				a[i][m - 1] = (i % 4 >= 2 ? 'y' : 'x');
			k2 -= n / 2;
		}
		for (int i = 0; i + 1 < n; i += 2) {
			for (int j = 0; j + 1 < m; j += 2) {
				if (k1) {
					k1 -= 2;
					if ((j / 2) % 2 == 0) {
						a[i][j] = a[i][j + 1] = 'a';
						a[i + 1][j] = a[i + 1][j + 1] = 'b';
					}
					else {
						a[i][j] = a[i][j + 1] = 'b';
						a[i + 1][j] = a[i + 1][j + 1] = 'a';
					}
				}
				else {
					k2 -= 2;
					if ((i / 2) % 2 == 0) {
						a[i][j] = a[i + 1][j] = 'c';
						a[i][j + 1] = a[i + 1][j + 1] = 'd';
					}
					else {
						a[i][j] = a[i + 1][j] = 'd';
						a[i][j + 1] = a[i + 1][j + 1] = 'c';
					}
				}
			}
		}
		if (k1 || k2) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
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