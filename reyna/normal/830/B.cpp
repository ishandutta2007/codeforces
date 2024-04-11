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

const int N = (int) 2e5 + 5, mod = (int) 0;
set<int> all[N];
int cnt[N], mark[N], f[N];
int query(int m) { ++m;
	int res = 0;
	while (m > 0)
		res += f[m], m -= m & -m;
	return res;
}
int query(int l, int r) {
	return query(r - 1) - query(l - 1);
}
void update(int m, int x) { ++m;
	while (m < N)
		f[m] += x, m += m & -m;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int cur_pos = 0;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		cnt[x]++;
		all[x].insert(j);
		all[x].insert(n + j);
		update(j, 1);
		update(j + n, 1);
	}
	int mn = 0;
	long long res = 0;
	int pos = 0;
	for (int use = 0; use < n; ++use) {
		while (!cnt[mn]) ++mn;
		while (true) {
			int nxt = *(all[mn].lower_bound(pos));
			if (mark[nxt % n]) {
				all[mn].erase(nxt);	
			} else {
				res += query(pos, nxt) + 1;
				mark[nxt % n] = 1;
				update(nxt % n, -1);
				update(nxt % n + n, -1);
				all[mn].erase(nxt);
				pos = nxt % n;
				break;
			}
		}
		--cnt[mn];
	}
	cout << res << endl;
}