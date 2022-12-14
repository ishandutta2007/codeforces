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
const int N = (int) 3005, mod = (int) 0;
pair<int, int> p[N];
int cnt[N], mark[N];
int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j)
		cin >> p[j].second >> p[j].first, --p[j].second, cnt[p[j].second]++;
	sort(p, p + n);
	int res = 1e18;
	for (int votes = 1; votes <= n; ++votes) {
		memset(cnt, 0, sizeof cnt);
		memset(mark, 0, sizeof mark);
		for (int j = 0; j < n; ++j)
			cnt[p[j].second]++;
		int init_votes = cnt[0];
		int cost = 0;
		for (int j = 0; j < n; ++j) {
			if (p[j].second != 0 && cnt[p[j].second] >= votes) {
				cost += p[j].first;
				init_votes++;
				--cnt[p[j].second];
				mark[j] = 1;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (p[j].second != 0 && init_votes < votes && !mark[j]) {
				init_votes++;
				cost += p[j].first;
			}
		}
		res = min(res, cost);
	}
	cout << res << endl;
}