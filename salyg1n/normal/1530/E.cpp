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
	string s;
	cin >> s;
	sort(all(s));
	int n = s.size();
	map<char, int> m;
	vi last(26);
	for (int i = 0; i < n; ++i) {
		m[s[i]]++;
		last[s[i] - 'a'] = i;
	}
	for (auto [c, b] : m) {
		if (b == 1) {
			swap(s[0], s[last[c - 'a']]);
			sort(s.begin() + 1, s.end());
			cout << s;
			cout << '\n';
			return;
		}
	}
	char a = m.begin()->first;
	string t;
	for (auto i : s)
		if (i != a)
			t += i;
	if (m[a] - 2 <= (n - 2) / 2) {
		cout << a << a;
		m[a] -= 2;
		int j = 0;
		for (int i = 0; i < n - 2; ++i) {
			if (i % 2 == 0 || !m[a])
				cout << t[j++];
			else {
				cout << a;
				m[a]--;
			}
		}
		cout << '\n';
	}
	else {
		if (m.size() <= 2) {
			sort(s.rbegin(), s.rend() - 1);
			cout << s << '\n';
			return;
		}
		char b = (++m.begin())->first, c = (++(++m.begin()))->first;
		cout << a << b;
		m[a]--;
		m[b]--;
		while (m[a]--)
			cout << a;
		cout << c;
		m[c]--;
		string t;
		for (auto [ch, cnt] : m) {
			for (int i = 0; i < cnt; ++i)
				t += ch;
		}
		sort(all(t));
		cout << t << '\n';
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