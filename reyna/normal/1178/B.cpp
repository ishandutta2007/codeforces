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

const int N = (int) 1e6 + 10, mod = (int) 0;
long long dp[N][4];
int main() {
	string s;
	cin >> s;
	long long res = 0;
	dp[0][0] = 1;
	int n = (int) s.size();
	for (int j = 0; j < n; ++j) {
		for (int turn = 0; turn < 3; ++turn) {
			if (turn == 0 || turn == 2) {
				if (j + 1 < n && s[j] == 'v' && s[j + 1] == 'v') {
					dp[j + 2][turn + 1] += dp[j][turn];	
				}
			} else {
				if (s[j] == 'o') {
					dp[j + 1][turn + 1] += dp[j][turn];
				}
			}
			dp[j + 1][turn] += dp[j][turn];
		}
	}
	for (int j = 0; j <= n; ++j)
		res += dp[j][3];
	cout << res << endl;
}