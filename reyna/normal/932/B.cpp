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
int s[10][N], dp[N];
int main() {
	for (int j = 0; j < N; ++j) {
		if (j < 10) {
			dp[j] = j;
		} else {
			int x = j, prod = 1;
			while (x) {
				if (x % 10) {
					prod *= x % 10;
				}
				x /= 10;
			}
			dp[j] = dp[prod];
		}
		for (int p = 0; p < 10; ++p)
			s[p][j + 1] = s[p][j] + (dp[j] == p);
		
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		++r;
		cout << s[k][r] - s[k][l] << '\n';
	}
}