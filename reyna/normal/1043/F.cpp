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
#define index toaru
const int N = (int) 3e5 + 5, M = 1 << 20, mod = (int) 0;
vector<int> d[N];
int g, dp[N], val[N], a[N], cnt[N], index[M], see[M];
int main() {
	memset(dp, 63, sizeof dp);
	for (int j = 0; j < 20; ++j) index[1 << j] = j;
	for (int i = 2; i < N; ++i)
		if (d[i].size() == 0)
			for (int j = i; j < N; j += i)
				d[j].pb(i);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		dp[x] = 1;
		if (j == 0) {
			g = x;
		} else {
			g = __gcd(g, x);
		}
		a[x] = 1;
	}
	if (g != 1) {
		cout << -1 << endl;
		return 0;
	}
	n = 0;
	for (int j = 0; j < N; ++j) n += a[j];
	for (int s = N - 1; s >= 0; --s) {
		if (a[s]) {
			val[0] = 1;
			cnt[1]++;
			for (int mask = 1; mask < (1 << (int) d[s].size()); ++mask) {
				int cur = index[mask & -mask];
				val[mask] = d[s][cur] * val[mask ^ (1 << cur)];
				cnt[val[mask]]++;
			}
		}
	}
	for (int s = N - 1; s >= 0; --s) {
		if (dp[s] < N) {
			val[0] = 1;
			see[0] = cnt[1];
			for (int mask = 1; mask < (1 << (int) d[s].size()); ++mask) {
				int cur = index[mask & -mask];
				val[mask] = d[s][cur] * val[mask ^ (1 << cur)];
				see[mask] = cnt[val[mask]];
			}
			for (int j = 0; j < d[s].size(); ++j)
				for (int mask = 0; mask < (1 << (int) d[s].size()); ++mask)
					if (~mask >> j & 1)
						see[mask] -= see[mask ^ (1 << j)];
			for (int mask = 0; mask < (1 << (int) d[s].size()); ++mask) {
				if (see[mask]) {
					dp[val[mask]] = min(dp[val[mask]], dp[s] + 1);
				}
			}			
		}
	}
	cout << dp[1] << endl;
}