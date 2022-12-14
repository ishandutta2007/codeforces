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

const int N = (int) 1e5 + 5, sq = 330, mod = (int) 0;
int dp[sq + 2][N], a[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	for (int jump = 1; jump <= sq; ++jump) {
		for (int j = n - 1; j >= 0; --j) {
			int nxt = j + a[j] + jump;
			if (nxt >= n) {
				dp[jump][j] = 1;
			} else {
				dp[jump][j] = dp[jump][nxt] + 1;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int res = 0, pos, k;
		cin >> pos >> k;
		--pos;
		if (k <= sq) {
			cout << dp[k][pos] << '\n';
			continue;
		}
		while (pos < n) {
			++res;
			pos = pos + a[pos] + k;
		}
		cout << res << '\n';
	}
}