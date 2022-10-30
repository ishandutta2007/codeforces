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

const int MAXN = 1e5 + 10, MOD = 1e9 + 7;
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

int cnt = 0;
bool ask(vi a) {
	if (cnt == 82)
		assert(0);
	cout << "? " << a.size() << " ";
	print(a);
	cout << endl;
	string s;
	cin >> s;
	return (s == "YES");
}

vi intersect(vi a, vi b) {
	vi res;
	sort(a);
	sort(b);
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j])
			i++;
		else if (a[i] > b[j])
			j++;
		else {
			res.push_back(a[i]);
			i++;
			j++;
		}
	}
	return res;
}

vi merge(vi a, vi b) {
	for (auto i : b)
		a.push_back(i);
	sort(a);
	a.erase(unique(all(a)), a.end());
	return a;
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	iota(all(a), 1);
	while (a.size() > 2) {
		n = a.size();
		int i1 = n / 4, i2 = n / 2, i3 = i1 + n / 2;
		if ((n - i3) - i1 >= 2) {
			i1++;
			i3++;
		}
		vi b, c, d, e;
		for (int i = 0; i < n; ++i) {
			if (i < i2)
				b.push_back(a[i]);
			else
				c.push_back(a[i]);
			if (i < i1 || i >= i3)
				d.push_back(a[i]);
			else
				e.push_back(a[i]);
		}
		bool s1, s2, s3, s4;
		s1 = ask(b);
		cnt++;
		s2 = ask(d);
		cnt++;
		s3 = ask(d);
		cnt++;
		s4 = ask(b);
		cnt++;
		if (s2 == s3) {
			if (s2)
				a = d;
			else
				a = e;
			continue;
		}
		if (s1 == s4) {
			if (s1)
				a = b;
			else
				a = c;
			continue;
		}
		if (s1 == s3)
			a = merge(intersect(b, d), intersect(c, e));
		else
			a = merge(intersect(b, e), intersect(c, d));
	}
	cout << "! " << a[0] << endl;
	string s;
	cin >> s;
	if (s == ":)")
		return;
	else
		cout << "! " << a[1] << endl;
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