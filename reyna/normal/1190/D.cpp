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
#define int long long
typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
int f[N], px[N], py[N];
vector<int> sweep[N];
void add_fen(int m, int x) { ++m;
	while (m < N) f[m] += x, m += m & -m;	
}
int query(int m) { ++m;
	int res = 0;
	while (m > 0) res += f[m], m -= m & -m;
	return res;
}
int query(int l, int r) {
	if (l >= r) return 0;
	return query(r - 1) - query(l - 1);
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> allx, ally;
	for (int j = 0; j < n; ++j) {
		cin >> px[j] >> py[j];
		allx.pb(px[j]);
		ally.pb(py[j]);
	}
	sort(ALL(allx));
	allx.resize(unique(ALL(allx)) - allx.begin());
	sort(ALL(ally));
	ally.resize(unique(ALL(ally)) - ally.begin());
	for (int j = 0; j < n; ++j) {
		px[j] = lower_bound(ALL(allx), px[j]) - allx.begin();
		py[j] = ally.size() - (lower_bound(ALL(ally), py[j]) - ally.begin()) - 1;
		sweep[py[j]].pb(j);
	}
	map<int, int> seen;
	int cnt = 0;
	long long res = 0;
	for (int level = 0; level < (int) ally.size(); ++level) {
		vector<int> all;
		for (int j : sweep[level]) all.pb(px[j]);
		sort(ALL(all));
		for (int x : all) if (!seen[x]++) {
			add_fen(x, 1);	
			++cnt;
		}
		res += (LL) cnt * (cnt + 1) / 2;
		int last = -1;
		for (int x : all) {
			int cur = query(last + 1, x);
			res -= (LL) cur * (cur + 1) / 2;
			last = x;
		}
		int cur = query(last + 1, N - 3);
		res -= (LL) cur * (cur + 1) / 2;
		
	}
	cout << res << endl;

}