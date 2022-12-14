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

const int N = (int) 605, mod = (int) 1e9 + 7;
map<vector<int>, int> s;
int f[N], dp[N], odp[N], comb[N][N];
void sadd(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int main() {
	f[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = (LL) f[j - 1] * j % mod;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		vector<int> v;
		for (int d = 2; d * d <= x; ++d) {
			int c = 0;
			while (x % d == 0) {
				x /= d;
				c ^= 1;
			}
			if (c) v.pb(d);
		}
		if (x != 1) v.pb(x);
		s[v]++;
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			comb[i][j] = (i == j || j == 0) ? 1 : (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	int all = 0, mul = 1;
	odp[0] = 1;
	for (auto pp : s) {
		int cnt = pp.second;
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		all += cnt;
		mul = (LL) mul * f[cnt] % mod;
		if (all == cnt) {
			dp[cnt - 1] = 1;
			continue;
		}
		for (int lemp = 0; lemp <= all - cnt; ++lemp) for (int chose = 0; chose <= lemp; ++chose) {
			for (int ot = 0; ot <= all - cnt + 1 - lemp && ot + chose <= cnt; ++ot) {
				int ways = odp[lemp] * (LL) comb[lemp][chose] % mod * comb[all - cnt + 1 - lemp][ot] % mod * comb[cnt - 1][ot + chose - 1] % mod;
				sadd(dp[lemp - chose + cnt - (ot + chose)], ways);
			}
		}
	}
	cout << dp[0] * (LL) mul % mod << endl;
}