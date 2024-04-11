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
	ll sum(int i, int j) {
		return sum(j) - sum(i);
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

int main() {
	int n; cin >> n;
	vector<int> x1(n), y1(n), x2(n), y2(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if (x1[i] > x2[i]) swap(x1[i], x2[i]);
		if (y1[i] > y2[i]) swap(y1[i], y2[i]);
	}
	vector<int> X, Y;
	for (int i = 0; i < n; i++) {
		X.push_back(x1[i]);
		X.push_back(x2[i]);
		Y.push_back(y1[i]);
		Y.push_back(y2[i]);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	int H = Y.size(), W = X.size();
	for (int i = 0; i < n; i++) {
		x1[i] = lower_bound(X.begin(), X.end(), x1[i]) - X.begin();
		x2[i] = lower_bound(X.begin(), X.end(), x2[i]) - X.begin();
		y1[i] = lower_bound(Y.begin(), Y.end(), y1[i]) - Y.begin();
		y2[i] = lower_bound(Y.begin(), Y.end(), y2[i]) - Y.begin();
	}
	vector<vector<int> > plus(H), minus(H);
	vector<vector<i_i> > a(H);
	for (int i = 0; i < n; i++)
		if (x1[i] == x2[i]) {
			plus[y1[i]].push_back(x1[i]);
			minus[y2[i]].push_back(x1[i]);
		}
		else a[y1[i]].push_back(i_i(x1[i], x2[i]));
	vector<int> d(W);
	bit b(W);
	ll ans = 0;
	for (int y = 0; y < H; y++) {
		for (int i = 0; i < plus[y].size(); i++) {
			int x = plus[y][i];
			d[x]++;
			if (d[x] == 1) b.add(x, 1);
		}
		ans += b.sum(0, W);
		sort(a[y].begin(), a[y].end());
		vector<i_i> v;
		for (int i = 0; i < a[y].size(); i++) {
			int x1 = a[y][i].first, x2 = a[y][i].second;
			if (v.empty() || v.back().second < x1)
				v.push_back(i_i(x1, x2));
			else
				v.back().second = max(v.back().second, x2);
		}
		for (int i = 0; i < v.size(); i++) {
			int x1 = v[i].first, x2 = v[i].second;
			ans += X[x2] - X[x1] + 1;
			ans -= b.sum(x1, x2 + 1);
		}
		for (int i = 0; i < minus[y].size(); i++) {
			int x = minus[y][i];
			d[x]--;
			if (d[x] == 0) b.add(x, -1);
		}
		if (y + 1 < H)
			ans += (Y[y + 1] - Y[y] - 1) * b.sum(0, W);
	}
	cout << ans << endl;
}