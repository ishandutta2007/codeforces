#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
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
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
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

vector<int> f(int n, vector<int>& p) {
	vector<int> a(n);
	bit b(n);
	for (int i = 0; i < n; i++) {
		a[n - i - 1] = p[i] - b.sum(p[i]);
		b.add(p[i], 1);
	}
	return a;
}

vector<int> g(int n, vector<int>& a) {
	vector<int> p(n);
	bit b(n);
	for (int i = 0; i < n; i++)
		b.add(i, 1);
	for (int i = 0; i < n; i++) {
		p[i] = b.lower_bound(a[n - i - 1] + 1) - 1;
		b.add(p[i], -1);
	}
	return p;
}

int main() {
	int n; cin >> n;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	vector<int> a = f(n, p), b = f(n, q);
	vector<int> c(n + 1);
	for (int i = 0; i < n; i++) {
		c[i] += a[i] + b[i];
		while (c[i] >= i + 1) {
			c[i] -= i + 1;
			c[i + 1]++;
		}
	}
	vector<int> r = g(n, c);
	for (int i = 0; i < n; i++)
		cout << r[i] << ' ';
	cout << endl;
}