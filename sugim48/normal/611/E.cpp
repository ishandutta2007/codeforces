#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
int INF = INT_MAX / 2;

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
	int lower_bound(ll x) {
		if (x <= 0) return 0;
		int res = 0;
		for (int i = 1 << 24; i > 0; i >>= 1)
			if (res + i < v.size() && v[res + i] < x) {
				res += i; x -= v[res];
			}
		return res + 1;
	}
};

int f(multiset<int>& s, int x) {
	auto it = s.upper_bound(x);
	if (it == s.begin()) return -1;
	it--;
	int tmp = *it;
	s.erase(it);
	return tmp;
}

int unko(multiset<int>& s, int m, vector<int>& v, bit& bt, int a, int b, int c) {
	if (s.empty()) return 0;
	auto it = s.end(); it--;
	if (*it > c) return INF;
	it = s.upper_bound(b);
	int C = bt.sum(m), i;
	if (it == s.end()) i = m;
	else i = lower_bound(v.begin(), v.end(), *it) - v.begin();
	int B = bt.sum(i);
	it = s.upper_bound(a);
	if (it == s.end()) i = m;
	else i = lower_bound(v.begin(), v.end(), *it) - v.begin();
	int A = bt.sum(i);
	return max(max(0, C - B), max((C - A + 1) / 2, (C + 2) / 3));
}

int main() {
	int n; cin >> n;
	int a, b, c; cin >> a >> b >> c;
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
	vector<int> t(n);
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		s.insert(t[i]);
	}
	auto it = s.upper_bound(a + b + c);
	if (it != s.end()) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for (;;) {
		if (s.empty()) break;
		it = s.end(); it--;
		if (*it <= b + c) break;
		ans++;
		s.erase(it);
	}
	for (;;) {
		if (s.empty()) break;
		it = s.end(); it--;
		if (*it <= a + c) break;
		ans++;
		s.erase(it);
		f(s, a);
	}
	int x = c, y = a + b;
	if (x > y) swap(x, y);
	for (;;) {
		if (s.empty()) break;
		it = s.end(); it--;
		if (*it <= y) break;
		ans++;
		s.erase(it);
		f(s, b);
	}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	int m = t.size();
	bit bt(m);
	for (auto it = s.begin(); it != s.end(); it++) {
		int i = lower_bound(t.begin(), t.end(), *it) - t.begin();
		bt.add(i, 1);
	}
	int mi = INF;
	for (;;) {
		mi = min(mi, ans + unko(s, m, t, bt, a, b, c));
		if (s.empty()) break;
		it = s.end(); it--;
		ans++;
		int i = lower_bound(t.begin(), t.end(), *it) - t.begin();
		bt.add(i, -1);
		s.erase(it);
		int z = f(s, x);
		if (z != -1) {
			int i = lower_bound(t.begin(), t.end(), z) - t.begin();
			bt.add(i, -1);
		}
	}
	cout << mi << endl;
}