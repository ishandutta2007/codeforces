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

const int MOD = 998244353;

int n;
string s;
pair<int, string> dfs(int v) {
	if (v >= (1 << n))
		return { 1, "" };
	auto [a, c] = dfs(2 * v);
	auto [b, d] = dfs(2 * v + 1);
	if (c > d) {
		swap(a, b);
		swap(c, d);
	}
	int res = a * b;
	string res1 = s[v - 1] + c + d;
	if (c != d)
		res *= 2;
	return { res % MOD, res1 };
}

void solve() {
	cin >> n;
	cin >> s;
	cout << dfs(1).first << "\n";
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