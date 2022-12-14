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

const int N = (int) 3e5 + 5, mod = (int) 0;
int mx[2], mn[2];
int pos[N];
char c[N];
vector<int> g;
vector<int> gs[N][2];
int mx_dist[N][2];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	memset(mx, -63, sizeof mx);
	memset(mn, 63, sizeof mn);
	for (int j = 0; j < n; ++j) {
		cin >> pos[j] >> c[j];
		if (c[j] == 'G') {
			g.push_back(pos[j]);	
		}
		if (c[j] != 'R') mx[0] = max(mx[0], pos[j]), mn[0] = min(mn[0], pos[j]);
		if (c[j] != 'B') mx[1] = max(mx[1], pos[j]), mn[1] = min(mn[1], pos[j]);
	}
	int res = max(0, mx[0] - mn[0]) + max(0, mx[1] - mn[1]);
	if ((int) g.size() > 1) {
		for (int j = 0; j < (int) g.size() - 1; ++j) {
			for (int col = 0; col <= 1; ++col) {
				gs[j][col].push_back(g[j]);	
			}
		}
		for (int j = 0; j < n; ++j) {
			int gr = -1;
			if (c[j] == 'R') {
				gr = 0;
			} else if (c[j] == 'B') {
				gr = 1;
			}
			if (gr >= 0) {
				int p = lower_bound(g.begin(), g.end(), pos[j]) - g.begin() - 1;
				if (p < (int) g.size() - 1) {
					gs[p][gr].push_back(pos[j]);
				}
			}
		}
		for (int j = 0; j < (int) g.size() - 1; ++j) {
			for (int col = 0; col <= 1; ++col) {
				gs[j][col].push_back(g[j + 1]);	
			}
		}
		for (int j = 0; j < (int) g.size() - 1; ++j) {
			for (int col = 0; col <= 1; ++col) {
				for (int i = 0; i < (int) gs[j][col].size() - 1; ++i) {
					mx_dist[j][col] = max(mx_dist[j][col], gs[j][col][i + 1] - gs[j][col][i]);	
				}
			}
			if (mx_dist[j][0] + mx_dist[j][1] >= g[j + 1] - g[j]) {
				res += (g[j + 1] - g[j]) - (mx_dist[j][0] + mx_dist[j][1]);	
			}
		}
	}
	cout << res << endl;
}