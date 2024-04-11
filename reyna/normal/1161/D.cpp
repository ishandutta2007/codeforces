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

const int N = (int) 2005, mod = (int) 998244353;
int par[N], sz[N], val[N], to_up[N];
string s;
int find(int v) {
	return v == par[v] ? v : find(par[v])	;
}
int findx(int v) { return v == par[v] ? 0 : to_up[v] ^ findx(par[v]); }
int unite(int u, int v, int x) {
	int xu = findx(u);
	int xv = findx(v);
	u = find(u);
	v = find(v);
	if (u == v && (xu ^ xv) != x) return 0; 
	else if (u == v) return 1;
	if (sz[u] > sz[v]) swap(u, v);
	to_up[u] = x ^ xu ^ xv;
	par[u] = v;
	sz[v] += sz[u];
	return 1;
}
int main() {
	cin >> s;
	int res = 0;
	int n = (int) s.size();
	for (int sz = 1; sz < n; ++sz) {
		for (int j = 0; j < N; ++j) ::sz[j] = 1, par[j] = j, to_up[j] = 0;
		int cur_res = 1;
		for (int j = 0; j < n; ++j)
			cur_res &= unite(j, n - j - 1, 0);
		for (int j = n; j < n + sz; ++j)
			cur_res &= unite(j, n + sz - (j - n) - 1, 0);
		cur_res &= unite(n + sz, n + sz + 1, 1);
		cur_res &= unite(n + sz + 1, 0, 0);
		cur_res &= unite(n + sz + 1, n, 0);
		for (int j = 0; j < n - sz; ++j)
			if (s[j] != '?')
				cur_res &= unite(n + sz, j, s[j] - '0');
		for (int j = n - sz; j < n; ++j) {
			int pos_a = j - (n - sz) + n;
			if (s[j] != '?') {
				cur_res &= unite(j, pos_a, s[j] - '0');
			}
		}
		int cnt = 0;
		for (int j = 0; j < n + sz + 2; ++j)
			if (par[j] == j)
				++cnt;
		--cnt;
		int tmp = cnt;
		while (cnt--) cur_res = (LL) cur_res * 2 % mod;
		res = (res + cur_res) % mod;
		
	}
	cout << res << endl;
}