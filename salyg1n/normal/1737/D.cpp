#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2")
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
#include <list>

#define int int_fast64_t

using namespace std;

typedef int_fast64_t ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double ld;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
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
	T& operator[](int i) {
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
template<typename T> T sum(vector<T> a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	int res = 0;
	for (; i <= j; ++i)
		res += a[i];
	return res;
}
template<typename T> void sort(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = (int)a.size() - 1;
	sort(a.begin() + i, a.begin() + (j + 1));
}
template<typename T> void rsort(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	sort(a.begin() + i, a.begin() + j + 1);
	reverse(a.begin() + i, a.begin() + j + 1);
}
template<typename T> void reverse(T& a, int i = 0, int j = -1) {
	if (j == -1)
		j = a.size() - 1;
	reverse(a.begin() + i, a.begin() + j + 1);
}

using namespace std;

const int MAXN = 1e6 + 10, MOD = 1e9 + 7;
const ld EPS = 1e-7;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}
int power(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		int tmp = power(a, n / 2);
		return tmp * tmp % MOD;
	}
	return power(a, n - 1) * a % MOD;
}
int fact[MAXN];
int Div(int a, int b) {
	return a * power(b, MOD - 2) % MOD;
}
int cnk(int n, int k) {
	return Div(fact[n], fact[k] * fact[n - k] % MOD);
}

vvi g1;
int n, m;

vi bfs(int v) {
	queue<int> q;
	q.push(v);
	vi d(n + 1, 1e18);
	d[v] = 0;
	while (q.size()) {
		v = q.front();
		q.pop();
		for (auto u : g1[v])
			if (minravno(d[u], d[v] + 1))
				q.push(u);
	}
	return d;
}

void solve() {
	cin >> n >> m;
	vvi g(n + 1, vi(n + 1, 1e18));
	g1.assign(n + 1, {});
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g1[u].push_back(v);
		g1[v].push_back(u);
		minravno(g[u][v], w);
		minravno(g[v][u], w);
	}
	vvi d(n + 1);
	for (int i = 1; i <= n; ++i) {
		d[i] = bfs(i);
	}
	int ans = 1e18;
	for (int v = 1; v <= n; ++v) {
		for (int u = 1; u <= n; ++u) {
			if (g[v][u] <= 2e9) {
				minravno(ans, (d[u][1] + d[v][n] + 1) * g[u][v]);
				minravno(ans, (d[u][n] + d[v][1] + 1) * g[u][v]);
				for (int k = 1; k <= n; ++k) {
					minravno(ans, (d[u][k] + 1 + d[k][n] + d[k][1] + 1) * g[u][v]);
					minravno(ans, (d[v][k] + 1 + d[k][n] + d[k][1] + 1) * g[u][v]);
				}
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}