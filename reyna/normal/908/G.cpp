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

const int N = (int) 705, mod = (int) 1e9 + 7;
int dp[N][N][2], cnt[N][N][2], p10[N];
string s;
/*
   int f(int pos, int more, int target, int eq = 1) {
   if (pos == (int) s.size()) {
   return 1;	
   }
   if (dp[pos][more][eq] != -1) {
   return dp[pos][more][eq];
   }
   int &res = dp[pos][more][eq]; res = 0;
   for (int dig = 0; dig <= (eq == 1 ? s[pos] - '0' : 9); ++dig) {
   int neq = (eq & (s[pos] - '0' == dig));
   int nmore = more + (dig != 0 && dig <= target);
   int npos = pos + 1;
   int nxt = f(npos, nmore, target, neq);
   if (dig == target) {
   res = (res + p10[more] * (LL) target) % mod;	
   } else {

   }
   }

   }
 */
int main() {
	cin >> s;
	p10[0] = 1;
	for (int j = 1; j < N; ++j)
		p10[j] = (p10[j - 1] * (LL) 10) % mod;
	int ans = 0;
	for (int target = 1; target <= 9; ++target) {
		memset(dp, 0, sizeof dp);
		memset(cnt, 0, sizeof cnt);
		dp[0][0][1] = 0;
		cnt[0][0][1] = 1;
		for (int pos = 0; pos < (int) s.size(); ++pos) {
			for (int more = 0; more <= pos; ++more) {
				for (int eq = 0; eq <= 1; ++eq) {
					int cur = dp[pos][more][eq], cur_cnt = cnt[pos][more][eq];
					for (int dig = 0; dig <= (eq == 1 ? s[pos] - '0' : 9); ++dig) {
						int neq = (eq & (s[pos] - '0' == dig));
						int nmore = more + (dig != 0 && dig >= target);
						int npos = pos + 1;
						int &nxt = dp[npos][nmore][neq];
						if (dig == target) {
							nxt = (nxt + p10[more] * (LL) target % mod * cur_cnt + cur) % mod;	
						} else if (dig > target) {
							nxt = (nxt + cur * (LL) 10) % mod;
						} else {
							nxt = (nxt + cur) % mod;	
						}
						cnt[npos][nmore][neq] = (cnt[npos][nmore][neq] + cur_cnt) % mod;
					}
				}
			}
		}
		int cur_res = 0;
		for (int more = 0; more <= (int) s.size(); ++more)
			for (int eq = 0; eq <= 1; ++eq) if (cnt[(int) s.size()][more][eq] && target) {
				cur_res = (cur_res + dp[(int) s.size()][more][eq]) % mod;
			}
		ans = (ans + cur_res) % mod;
	}
	cout << ans << endl;
}