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

const int N = (int) 1e5 + 5, M = 205, mod = (int) 998244353;
int dp[M][2], odp[M][2], a[N];
void sadd(int &x, int y) {
	x = (x + y) % mod;	
}
int main() {
	int n;
	cin >> n;
	dp[0][0] = 1;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		
		int sumall = 0, sum0 = odp[0][0], sum1 = 0;
		for (int i = 0; i <= 200; ++i) sadd(sumall, odp[i][1]);
		for (int i = 1; i <= 200; ++i) {
			if (i == a[j] || a[j] == -1) {
				sadd(dp[i][0], sum0);
				sadd(dp[i][0], sum1);
				/*
				for (int k = 0; k < i; ++k) {
					sadd(dp[i][0], odp[k][0]);
					sadd(dp[i][0], odp[k][1]);
				}
				*/
				sadd(dp[i][1], sumall);
				sadd(dp[i][1], odp[i][0]);
			}
			sadd(sumall, (mod - odp[i][1]) % mod);
			sadd(sum0, odp[i][0]);
			sadd(sum1, odp[i][1]);
		}
	}
	int res = 0;
	for (int j = 1; j <= 200; ++j)
		sadd(res, dp[j][1]);
	cout << res << endl;
}