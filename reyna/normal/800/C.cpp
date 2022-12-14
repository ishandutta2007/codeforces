// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 2e5 + 5;
int gcd(int x, int y) {
	return min(x, y) == 0 ? max(x, y) : __gcd(x, y);
}
int fpm(int a, int b, int mod) { return b != 0 ? fpm((LL) a * a % mod, b >> 1, mod) * (LL) (b & 1 ? a : 1) % mod: 1; }
int n, m, mark[N], dp[N], par[N], cnt, res_arr[N], phi[N];
vector<int> all[N];
int show(int x) {
	if (x == -1) return 1;
	int cur = show(par[x]);
	for (int num : all[x]) {
		int g = __gcd(cur, m);
		int inverse = fpm(cur / g, phi[m / g] - 1, m / g);
		int t = (LL) inverse % m;
		t = (LL) t * (num / g) % m;
		res_arr[cnt++] = t;
//		cout << " hey " << num << ' ' << x << ' ' << cur << ' ' << inverse << ' ' << g << ' ' << t << endl;
		cur = num;
	}
	return cur;
}
int main() {
	vector<int> dv;
	cin >> n >> m;
	for (int j = 1; j < N; ++j) phi[j] = j;
	for (int j = 2; j < N; ++j) {
		if (phi[j] == j) {
			for (int i = j; i < N; i += j)
				phi[i] -= phi[i] / j;
		}
	}
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		mark[x] = 1;
	}
	for (int j = 0; j < m; ++j) {
		int g = __gcd(j, m);
		if (!mark[j])
			all[g].pb(j);
	}
	for (int j = 1; j <= m; ++j)
		if (m % j == 0)
			dv.push_back(j);
	memset(par, -1, sizeof par);
	for (int x : dv) {
		dp[x] = SZ(all[x]);
		for (int y : dv) {
			if (x == y) break;
			if (x % y != 0) continue;
			if (dp[y] + SZ(all[x]) >= dp[x]) {
				dp[x] = dp[y] + SZ(all[x]);
				par[x] = y;
			}
		}
	}
	cout << dp[m] << endl;
	show(m);
	for (int j = 0; j < cnt; ++j) {
		cout << res_arr[j] << ' ';
	}
	cerr << endl;
	for (int j = 0; j < cnt; ++j) {
		if (j >= 1) res_arr[j] = (LL) res_arr[j - 1] * res_arr[j] % m;
		cerr << res_arr[j] << ' ';
	}
}