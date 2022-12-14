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

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], mxpre[N][2], mnpre[N][2], mxsuf[N][2], mnsuf[N][2];
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int j = 0; j <= n; ++j) {
		for (int turn = 0; turn <= 1; ++turn) {
			mxpre[j][turn] = -1;
			mnpre[j][turn] = n;
			mxsuf[j][turn] = -1;
			mnsuf[j][turn] = n;
		}
	}
	for (int j = 0; j < n; ++j) {
		for (int turn = 0; turn <= 1; ++turn) {
			mxpre[j + 1][turn] = mxpre[j][turn];
			mnpre[j + 1][turn] = mnpre[j][turn];
			if (s[j] == turn + '0') {
				mxpre[j + 1][turn] = max(mxpre[j + 1][turn], j);
				mnpre[j + 1][turn] = min(mnpre[j + 1][turn], j);
			}
		}
	}
	
	for (int j = n - 1; j >= 0; --j) {
		for (int turn = 0; turn <= 1; ++turn) {
			mxsuf[j][turn] = mxsuf[j + 1][turn];
			mnsuf[j][turn] = mnsuf[j + 1][turn];
			if (s[j] == turn + '0') {
				mxsuf[j][turn] = max(mxsuf[j][turn], j);
				mnsuf[j][turn] = min(mnsuf[j][turn], j);
			}
		}
	}
	int can = 0;
	for (int pos = 0; pos < n - k + 1; ++pos) {
		for (int turn = 0; turn <= 1; ++turn) {
			int ot = turn ^ 1;	
			int r = max(mxpre[pos][ot], mxsuf[pos + k][ot]);
			int l = min(mnpre[pos][ot], mnsuf[pos + k][ot]);
			if (l > r) {
				cout << "tokitsukaze\n";
				return 0;
			}
			++r;
			if (r - l > k) {
				can = 1;	
			}
		}
	}
	if (can) {
		cout << "once again\n";
		return 0;
	}
	cout << "quailty\n";
}