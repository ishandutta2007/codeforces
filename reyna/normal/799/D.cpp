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
const int N = (int) 2e5 + 5, mod = (int) 0;
int sz[N], dp[N], odp[N];
int32_t main() {
	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	for (int j = 0; j < n; ++j) {
		cin >> sz[j];
	}
	sort(sz, sz + n);
	reverse(sz, sz + n);
	dp[h] = 1;
	for (int j = 0; j <= min(n, 50LL); ++j) {
		for (int k = a; k < N; ++k) if (dp[k] * w >= b) {
			cout << j << endl;
			return 0;
		}
		for (int k = b; k < N; ++k) if (dp[k] * w >= a) {
			cout << j << endl;
			return 0;
		}
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		if (j != n) {
			for (int k = 0; k < N; ++k) {
				int nxt = min(k * sz[j], N - 1);
				dp[k] = max(dp[k], min(N, odp[k] * sz[j]));
				dp[nxt] = max(dp[nxt], min(N, odp[k]));
			}
		}
	}
	cout << -1 << endl;
	return 0;
}