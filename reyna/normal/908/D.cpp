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

const int N = (int) 2005, mod = (int) 1e9 + 7;

int dp[N][N];
int pw(int a, int b) { return b == 0 ? 1 : pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod; }
int main() {
	int k, pa, pb;
	cin >> k >> pa >> pb;
	int ac = (LL) pa * pw(pa + pb, mod - 2) % mod;
	int bc = (LL) pb * pw(pa + pb, mod - 2) % mod;
	dp[0][1] = 1;
	int res = 0;
	for (int x = 0; x < k; ++x)
		for (int y = 1; x + y <= 2 * k; ++y) {
			if (x + y >= k) {
				int cur = dp[x][y];
				if (x + y - 1 >= k) {
					cur = (cur - (dp[x][y - 1] * (LL) ac) % mod + mod) % mod;	
				}
				res = (res + (LL) cur * ((x + y) + ac * (LL) pw((1 - ac + mod) % mod, mod - 2) % mod)) % mod;
			}
			{
				dp[x + y][y] = (dp[x + y][y] + (LL) dp[x][y] * bc) % mod;
				dp[x][y + 1] = (dp[x][y + 1] + (LL) dp[x][y] * ac) % mod;
			}
		}
	cout << res << endl;
}