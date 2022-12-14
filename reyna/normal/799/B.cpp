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

const int N = (int) 1e6 + 6, mod = (int) 0;
set<pair<int, int>> st[10];
int mark[N], a[N], b[N], p[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> p[j];
	for (int j = 0; j < n; ++j) cin >> a[j], st[a[j]].insert(mp(p[j], j));
	for (int j = 0; j < n; ++j) cin >> b[j], st[b[j]].insert(mp(p[j], j));
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		int res = -1;
		while ((int) st[c].size()) {
			auto cur = *(st[c].begin());
			if (mark[cur.second]) {
				st[c].erase(cur);
			} else {
				res = cur.first;
				mark[cur.second] = 1;
				break;
			}
		}
		cout << res << ' ';
	}
}