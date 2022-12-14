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

const int N = (int) 1e5 + 5, mod = (int) 0;
int dp[N], odp[N], a[N], o[N], b[N], sum[N];
int cmp(int x, int y) {
	return b[x] > b[y];	
}
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], o[j] = j;
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for (int bit = 0; bit < 62; ++bit) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 63, sizeof dp);
		for (int j = 0; j < n; ++j) {
			b[j] = a[j] & ((1ll << (bit)) - 1);
		}
		sort(o, o + n, cmp);
		for (int j = 0; j < n; ++j) {
			int i = o[j];
			sum[j + 1] = sum[j] + (a[i] >> bit & 1);	
		}
		for (int over = 0; over <= n; ++over) {
			int cur_nover = sum[over];
			int ones = over - sum[over] + sum[n] - sum[over];
			int zeros = n - ones;
			{
				int add = ones;
				int nover = cur_nover + add;
				dp[nover] = min(dp[nover], odp[over] + add);
			}
			{
				int add = zeros;
				int nover = cur_nover;
				dp[nover] = min(dp[nover], odp[over] + add);
			}
		}
	}
	cout << dp[0] << '\n';
}