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

const int N = (int) 4005, mod = (int) 0;
int dp[N][N], b[N][N];
string s[N];
string best;
int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j)
		cin >> s[j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int res = i + j;
			if (i > 0) res = min(res, b[i - 1][j]);
			if (j > 0) res = min(res, b[i][j - 1]);
			b[i][j] = res + (s[i][j] != 'a');
		}
	int st = 0;
	for (int sum = n + n - 2; sum >= 0; --sum) {	
		int should = 0;
		for (int j = 0; j <= min(n - 1, sum); ++j) {
			int i = sum - j;
			if (i >= n) continue;
			if (b[i][j] <= k) {
				should = 1;
			}
		}
		char c = 'z' + 1;
		if (should) {
			
			for (int j = 0; j <= min(n - 1, sum); ++j) {
				int i = sum - j;
				if (i >= n) continue;
				if (b[i][j] <= k) {
					dp[i][j] = 1;
					st = sum + 1;
				}
			}
			break;
		}
	}
	for (int j = 0; j < st; ++j) best += 'a';
	if (st == 0) {
		dp[0][0] = 1;	
		best += s[0][0];
		++st;
	}
	for (int sum = st; sum < n + n - 1; ++sum) {
		char c = 1 + 'z';
		for (int j = 0; j <= min(n - 1, sum); ++j) {
			int i = sum - j;
			if (i >= n) continue;
			if (i > 0 && dp[i - 1][j] && s[i][j] < c) c = s[i][j];
			if (j > 0 && dp[i][j - 1] && s[i][j] < c) c = s[i][j];
		}
		for (int j = 0; j <= min(n - 1, sum); ++j) {
			int i = sum - j;
			if (i >= n) continue;
			int can = 0;
			if (i > 0 && dp[i - 1][j] && s[i][j] == c) can = 1;
			if (j > 0 && dp[i][j - 1] && s[i][j] == c) can = 1;
			if (can) {
				dp[i][j] = 1;
			}
		}
		best += c;
	}
	cout << best << endl;
}