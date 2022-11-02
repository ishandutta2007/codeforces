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
	if (!n)
		return 1;
	if (n % 2 == 0) {
		int tmp = power(a, n / 2);
		return tmp * tmp % MOD;
	}
	return power(a, n - 1) * a % MOD;
}

void solve() {
	int R, G, B;
	cin >> R >> G >> B;
	vi r(R + 1), g(G + 1), b(B + 1);
	input(r, 1);
	input(g, 1);
	input(b, 1);
	sort(r, 1);
	sort(g, 1);
	sort(b, 1);
	vvvi dp(R + 1, vvi(G + 1, vi(B + 1, 0)));
	for (int i = 0; i <= R; ++i) {
		for (int j = 0; j <= G; ++j) {
			for (int k = 0; k <= B; ++k) {
				if ((!i) + (!j) + (!k) >= 2)
					continue;
				if (!i)
					dp[i][j][k] = g[j] * b[k] + dp[i][j - 1][k - 1];
				else if (!j)
					dp[i][j][k] = r[i] * b[k] + dp[i - 1][j][k - 1];
				else if (!k)
					dp[i][j][k] = r[i] * g[j] + dp[i - 1][j - 1][k];
				else
					dp[i][j][k] = max({ r[i] * g[j] + dp[i - 1][j - 1][k], r[i] * b[k] + dp[i - 1][j][k - 1], g[j] * b[k] + dp[i][j - 1][k - 1] });
			}
		}
	}
	cout << dp[R][G][B];
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