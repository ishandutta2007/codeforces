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

const int N = (int) 55, mod = (int) 1e9 + 7;
int fpm(int a, int b) { return b == 0 ? 1 : fpm((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod; }
int dp[N][N], add[N][N];
void sadd(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int main() {
	int n, m;
	cin >> n >> m;
	n += 2;
	dp[0][0] = 1;
	dp[2][1] = 1;
	for (int j = 3; j <= n; ++j) {
		for (int cntl = 1; cntl <= j - 2; ++cntl) {
			int cntr = j - 2 - cntl + 1;
			for (int cutl = 0; cutl <= cntl + 1; ++cutl)
				for (int cutr = 0; cutr <= cntr + 1; ++cutr)
					sadd(add[j - 2][min(cutl, cutr)], dp[cntl + 1][cutl] * (LL) dp[cntr + 1][cutr] % mod);
		}
		if (j > 2) {
			for (int cut = 0; cut <= n; ++cut) {
				for (int pick = 1; pick <= j - 2; ++pick) {
					for (int cutl = 0; cutl <= cut; ++cutl) {
						for (int cntp = pick, cutp = cutl; cntp <= j - 2 && cutp <= cut; cutp += cutl, cntp += pick) {
							sadd(dp[j][cut], dp[j - cntp][cut - cutp] * (LL) add[pick][cutl] % mod * pick % mod);
						}
					}
				}
			}
			for (int cut = 0; cut <= j + 1; ++cut) {
				dp[j][cut] = (LL) dp[j][cut] * fpm(j - 2, mod - 2) % mod;			
			}
		}
	}
	cout << dp[n][m] << endl;
}