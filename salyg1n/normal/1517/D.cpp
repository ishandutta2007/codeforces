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

template<typename T> void print(const T& a, int i = 0, char c = ' ') {
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

template<typename T> T max(vector<T> a, int i = 0) {
	return *max_element(a.begin() + i, a.end());
}

const int MAXN = 510, MAXK = 21;

vi di = { 1,-1, 0, 0 };
vi dj = { 0, 0, 1, -1 };

int g[MAXN][MAXN][4];
int dp[MAXN][MAXN][MAXK];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			int x;
			cin >> x;
			g[i][j][2] = g[i][j + 1][3] = x;
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			cin >> x;
			g[i][j][0] = g[i + 1][j][1] = x;
		}
	}
	for (int l = 0; l < MAXK; ++l) {
		for (int i = 0; i <= n + 1; ++i)
			dp[i][0][l] = dp[i][m + 1][l] = 1e18;
		for (int i = 0; i <= m + 1; ++i)
			dp[0][i][l] = dp[n + 1][i][l] = 1e18;
	}
	for (int l = 2; l <= k; l += 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dp[i][j][l] = 1e18;
				for (int h = 0; h < 4; ++h) {
					int x = i + di[h];
					int y = j + dj[h];
					minravno(dp[i][j][l], dp[x][y][l - 2] + g[i][j][h] + g[x][y][h ^ 1]);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (k % 2)
				cout << "-1 ";
			else
				cout << dp[i][j][k] << " ";
		}
		cout << "\n";
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