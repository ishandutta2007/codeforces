#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
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
struct edge { int v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

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
};

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n), v;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		v.push_back(a[i]);
		v.push_back(b[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int m = v.size();
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
	}
	vector<int> q(m);
	for (int j = 0; j < m; j++)
		q[j] = j;
	for (int i = 0; i < n; i++)
		swap(q[a[i]], q[b[i]]);
	ll inv = 0;
	bit bt(m);
	for (int j = m - 1; j >= 0; j--) {
		inv += bt.sum(q[j]);
		bt.add(q[j], 1);
	}
	for (int j = 0; j < m; j++) {
		int x = j, y = q[j];
		if (x > y) swap(x, y);
		inv += (v[y] - v[x] - 1) - (y - x - 1);
	}
	cout << inv << endl;
}