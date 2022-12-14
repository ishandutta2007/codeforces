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
const int N = (int) 55, mod = (int) 0;
int n, k, dp[N][N], a[N];
int can(int val) {
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int r = 1; r <= n; ++r) for (int ck = 1; ck <= k; ++ck) {
		int sum = 0;
		for (int l = r - 1; l >= 0; --l) {
			sum += a[l];
			if ((sum & val) == val) {
				dp[r][ck] |= dp[l][ck - 1];	
			}
		}
	}	
	return dp[n][k];
}
int32_t main() {
	cin >> n >> k;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int cur = 0;
	for (int j = 60; j >= 0; --j) {
		int nxt = cur | (1LL << j);
		if (can(nxt)) {
			cur = nxt;	
		}
	}
	cout << cur << endl;
}