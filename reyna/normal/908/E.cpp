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

const int N = (int) 2005, mod = (int) 1e9 + 7;
int comb[N][N], dp[N], par[N], comp[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	par[u] = v;
}
string s[N];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			comb[i][j] = (i == j || !j) ? 1 : (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	dp[1] = 1;
	for (int sz = 2; sz < N; ++sz) {
		for (int i = 1; i <= sz - 1; ++i) {
			dp[sz] = (dp[sz] + dp[sz - i] * (LL) comb[sz - 1][i - 1]) % mod;	
		}
		dp[sz] = (dp[sz] + 1) % mod;
	}
	for (int j = 0; j < m; ++j) par[j] = j;
	for (int j = 0; j < n; ++j)
		cin >> s[j];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			int same = 1;
			for (int k = 0; k < n; ++k)
				same &= (s[k][i] == s[k][j]);
			if (same) {
				unite(i, j);
			}
		}
	for (int j = 0; j < m; ++j) comp[find(j)]++;
	int res = 1;
	for (int j = 0; j < m; ++j)
		if (par[j] == j) {
			res = (res * (LL) dp[comp[j]]) % mod;
		}
	cout << res << endl;
}