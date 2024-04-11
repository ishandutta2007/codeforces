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
const int N = (int) 1e6 + 6, mod = (int) 0;
int s[N], t[N], cnt[N], par[N], deg[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void unite(int u, int v) {
	par[find(u)] = find(v);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j)
		par[j] = j;
	int loops = 0;
	for (int j = 0; j < m; ++j) {
		int &u = s[j], &v = t[j];
		cin >> u >> v;
		--u, --v;
		if (u == v) {
			++loops;
		} else {
			unite(u, v);
			deg[u]++;
			deg[v]++;
		}
	}
	for (int j = 0; j < m; ++j)
		cnt[find(s[j])]++;
	int nzero = 0;
	for (int j = 0; j < n; ++j)
		if (par[j] == j)
			nzero += !!cnt[j];
	if (nzero > 1) {
		cout << 0 << endl;
		return 0;
	}
	long long res = (loops * (loops - 1)) / 2 + loops * (m - loops);
	for (int j = 0; j < n; ++j)
		res += (deg[j] * (deg[j] - 1)) / 2;
	cout << res << endl;
}