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

const int N = (int) 1005, M = 1e5 + 5, mod = (int) 998244353;
int sum[N][N], a[N], comb[N][N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int x = 0; x < N; ++x)
		for (int y = 0; y < N; ++y)
			comb[x][y] = (y == 0 || x == y) ? 1 : (comb[x - 1][y - 1] + comb[x - 1][y]) % mod;
	for (int j = 0; j < n; ++j) cin >> a[j];
	sort(a, a + n);
	long long res = 0;
	for (int val = 1; val <= M / (k - 1) + 1; ++val) {
		for (int j = 0; j < n; ++j) for (int i = 0; i <= k; ++i) sum[j][i] = 0;
		int pt = 0;
		for (int j = 0; j < n; ++j) {
			while (a[j] - a[pt] >= val) {
				++pt;
			}
			sum[j + 1][1] = 1;
			for (int i = 2; i <= k; ++i) {
				sum[j + 1][i] = sum[pt][i - 1];
				if (sum[j + 1][i] >= mod)
					sum[j + 1][i] -= mod;
			}
			for (int i = 1; i <= k; ++i) {
				sum[j + 1][i] += sum[j][i];
				if (sum[j + 1][i] >= mod)
					sum[j + 1][i] -= mod;
			}
		}
		res += sum[n][k];
		res %= mod;
		
	}
	cout << res << endl;
}