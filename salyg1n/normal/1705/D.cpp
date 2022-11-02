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

int randint(int a, int b) {
	return rnd() % (b - a + 1) + a;
}

int n;
vector<int> fenv;

void update(int i, int x) {
	for (; i <= n; i += i & -i)
		fenv[i] += x;
}

int get(int i) {
	int res = 0;
	for (; i >= 1; i -= i & -i)
		res += fenv[i];
	return res;
}

void solve() {
	string s, t;
	cin >> n >> s >> t;
	fenv.assign(n + 1, 0);
	si a;
	for (int i = 1; i < n - 1; ++i)
		if (s[i - 1] != s[i + 1])
			a.insert(i);
	if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
		cout << "-1\n";
		return;
	}
	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		int c = s[i];
		if (get(i) % 2)
			c = (c == '0' ? '1' : '0');
		if (c == t[i])
			continue;
		while (a.size() && *a.begin() < i)
			a.erase(a.begin());
		if (!a.size()) {
			cout << "-1\n";
			return;
		}
		update(i, 1);
		update(*a.begin() + 1, -1);
		ans += *a.begin() - i + 1;
		if (*a.begin() != n - 2) {
			if (a.count(*a.begin() + 1))
				a.erase(*a.begin() + 1);
			else
				a.insert(*a.begin() + 1);
		}
		a.erase(a.begin());
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