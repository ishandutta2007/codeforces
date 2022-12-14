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
int dp[N], par[N], cnt;
void show(int n) {
	if (!n) return;
	for (int j = 0; j < par[n]; ++j) cout << char(cnt + 'a');
	++cnt;
	show(n - par[n] * (par[n] - 1) / 2);
}
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 'a';
		return 0;
	}
	dp[0] = 0;
	int mx = 0;
	for (int j = 1; j <= n; ++j) {
		int l2 = 0;
		dp[j] = N;
		for (int last = 1; l2 <= j; ++last) {
			if (dp[j - l2] + 1 < dp[j]) {
				dp[j] = dp[j - l2] + 1;
				par[j] = last;
			}
			assert(l2 == last * (last - 1) / 2);
			l2 += last;
		}
		mx = max(mx, dp[j]);
	}
	show(n);
}