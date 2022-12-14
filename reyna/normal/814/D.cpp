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
const int N = (int) 1005, mod = (int) 0;
int o[N], px[N], py[N], pr[N];
vector<int> adj[N];
int by_pr(int x, int y) { return pr[x] > pr[y]; }
const double pi = acos(-1.);
double dp[N][2][2], odp[N][2][2];
double area(int v) {
	return pi * pr[v] * pr[v];	
}
void dfs(int v) {
	for (int u : adj[v]) {
		dfs(u);
		for (int a = 0; a <= 1; ++a)
			for (int b = 0; b <= 1; ++b)
				odp[v][a][b] += dp[u][a][b];
	}
	for (int a = 0; a <= 1; ++a)
		for (int b = 0; b <= 1; ++b)
			dp[v][a][b] = -1e18;
	for (int a = 0; a <= 1; ++a)
		for (int b = 0; b <= 1; ++b) {
			for (int c = 0; c <= 1; ++c) {
				int na = a, nb = b, use = 1;
				if (v != 0) {
					if (c == 0) {
						na ^= 1;
						if (na == 0) use = -1;	
					}
					if (c == 1) {
						nb ^= 1;
						if (nb == 0) use = -1;
					}
				}
				dp[v][na][nb] = max(dp[v][na][nb], odp[v][a][b] + use * area(v));
			}
		}
}
int32_t main() {
	int n;
	cin >> n;
	for (int j = 1; j <= n; ++j) {
		cin >> px[j] >> py[j] >> pr[j];
		o[j - 1] = j;
	}
	sort(o, o + n, by_pr);
	for (int ax = 0; ax < n; ++ax) {
		int p = 0;
		int x = o[ax];
		for (int bx = ax - 1; bx >= 0; --bx) {
			int y = o[bx];
			double dist = sqrt((px[x] - px[y]) * (px[x] - px[y]) + (py[x] - py[y]) * (py[x] - py[y]));
			if (dist < pr[y]) {
				p = y;
				break;
			}
		}
		adj[p].push_back(x);
	}
	dfs(0);
	cout << setprecision(10) << fixed << dp[0][1][1] << endl;
}