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
#define int long long
const int N = (int) 1e5 + 5, M = 11, mod = (int) 0;
int rev[M][N];
int a[M][N];
int par[N], sz[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) { par[find(u)] = find(v); }
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m, t = 0;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) par[j] = j;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			cin >> a[j][i];
			--a[j][i];
			rev[j][a[j][i]] = i;
		}
	}
	for (int j = 0; j < n; ++j) {
		int nxt = (rev[0][j] + 1 == n ? -1 : a[0][rev[0][j] + 1]);
		for (int i = 1; i < m; ++i) {
			if (rev[i][j] + 1 == n) {
				nxt = -1;
			} else {
				if (nxt != a[i][rev[i][j] + 1]) {
					nxt = -1;
				}
			}
		}
		if (nxt != -1) {
			unite(j, nxt);
		}
	}
	for (int j = 0; j < n; ++j) sz[find(j)]++;
	int res = 0;
	for (int j = 0; j < n; ++j) if (par[j] == j) res += sz[j] * (sz[j] + 1) / 2;
	cout << res << endl;
}