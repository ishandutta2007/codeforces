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

const int N = (int) 1e6 + 5, mod = (int) 0;
int g[N], p[N], t[N];
pair<int, int> res[N];
pair<int, pair<int, int>> sr[N], ot[N];
map<int, vector<int>> all;
int main() {
	ios_base::sync_with_stdio(0);
	int n, w, h;
	cin >> n >> w >> h;
	for (int j = 0; j < n; ++j) {
		cin >> g[j] >> p[j] >> t[j];	
		all[t[j] - p[j]].push_back(j);
	}
	for (auto vv : all) {
		int cnt = 0;
		vector<int> v = vv.second;
		for (int x : v) {
			sr[cnt] = mp(3 - g[x], mp((g[x] == 1 ? p[x] : -p[x]), x));	
			ot[cnt] = mp(g[x], mp((g[x] == 1 ? p[x] : -p[x]), x));
			++cnt;
		}
		sort(ot, ot + cnt);
		sort(sr, sr + cnt);
		for (int j = 0; j < cnt; ++j) {
			int id = sr[j].second.second;
			int cp = ot[j].second.second;
			if (g[cp] == 2) {
				res[id] = mp(w, p[cp]);	
			} else {
				res[id] = mp(p[cp], h);
			}
		}
	}
	for (int j = 0; j < n; ++j)
		cout << res[j].first << ' ' << res[j].second << '\n';
}