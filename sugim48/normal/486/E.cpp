#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <fstream>
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
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

struct bit {
	vector<ll> w;
	bit(int n) : w(n + 1, 0) {}
	ll maxi(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res = max(res, w[i]);
		return res;
	}
	void update(int i, ll x) {
		for (i++; i < w.size(); i += i & -i)
			w[i] = max(w[i], x);
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	bit b(100001);
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = b.maxi(a[i]) + 1;
		b.update(a[i], dp[i]);
	}
	int m = b.maxi(100001);
	vector<int> v(m + 2);
	v[m + 1] = INT_MAX;
	vector<bool> f(n);
	vector<int> g(m + 1);
	for (int i = n - 1; i >= 0; i--) {
		int j = dp[i];
		if (a[i] < v[j + 1]) {
			v[j] = max(v[j], a[i]);
			f[i] = true;
			g[j]++;
		}
	}
	for (int i = 0; i < n; i++)
		if (f[i]) {
			int j = dp[i];
			cout << (g[j] == 1 ? '3' : '2');
		}
		else cout << '1';
	cout << endl;
}