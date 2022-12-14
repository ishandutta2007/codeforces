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


typedef long long LL;
int smin(int &x, int y) { return x = min(x, y); }
const int N = (int) 205, mod = (int) 0;
int dp[2][N][N], odp[2][N][N], vsum[N], ksum[N], nsum[N], posv[N], posk[N], szk, szv;
char s[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> s[j];
		char x = s[j];
		if (x == 'V') {
			posv[szv++] = j;
		} else if (x == 'K') {
			posk[szk++] = j;
		}
		vsum[j + 1] = vsum[j] + (x == 'V');
		ksum[j + 1] = ksum[j] + (x == 'K');
		nsum[j + 1] = nsum[j] + (x != 'K' && x != 'V');
	}
	memset(dp, 63, sizeof dp);
	dp[0][0][0] = 0;
	for (int use = 1; use <= n; ++use) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 63, sizeof dp);
		for (int vp = 0; vp <= szv; ++vp) {
			for (int kp = 0; kp <= szk; ++kp) {
				for (int lv = 0; lv <= 1; ++lv) {
					int np = use - vp - kp;
					if (np < 0) continue;
					if (vp > 0) {
						int pos = posv[vp - 1];
						int add = abs(nsum[pos] - np) + abs(ksum[pos] - kp);
						smin(dp[1][vp][kp], odp[lv][vp - 1][kp] + add);
					}
					if (kp > 0 && !lv) {
						int pos = posk[kp - 1];
						int add = abs(nsum[pos] - np);
						smin(dp[0][vp][kp], odp[lv][vp][kp - 1] + add);
					}
					if (np > 0) {
						smin(dp[0][vp][kp], odp[lv][vp][kp]);
					}
				}
			}
		}
	}
	cout << min(dp[0][szv][szk], dp[1][szv][szk]) << endl;
}