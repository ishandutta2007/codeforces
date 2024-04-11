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

const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
struct data {
	int a2, a, cnt;
	data() {
		a2 = a = 0;
		cnt = 1;
	}
	data(int x) {
		a2 = (LL) x * x % mod;
		a = x;
		cnt = 2;
	}
} dp[N];
data operator + (data a, data b) {
	data res;
	res.a2 = ((LL) a.a2 * b.cnt + (LL) b.a2 * a.cnt) % mod;
	res.a2 = (res.a2 + (LL) 2 * a.a * b.a) % mod;
	res.a = ((LL) a.a * b.cnt + (LL) b.a * a.cnt) % mod;
	res.cnt = ((LL) a.cnt * b.cnt) % mod;
	return res;
}
int p10[9], res[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	p10[0] = 1;
	for (int j = 1; j < 9; ++j)
		p10[j] = p10[j - 1] * 10;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		dp[x] = dp[x] + data(x);
	}
	for (int d = 0; d < 6; ++d) {
		for (int j = p10[6] - 1; j >= 0; --j) {
			if (j % p10[d + 1] < p10[d + 1] - p10[d]) {
				dp[j] = dp[j] + dp[j + p10[d]];
			}
		}
	}
	for (int j = 0; j < p10[6]; ++j) res[j] = dp[j].a2;
	for (int d = 0; d < 6; ++d) {
		for (int j = 0; j < p10[6]; ++j) {
			if (j % p10[d + 1] < p10[d + 1] - p10[d]) {
				res[j] = (res[j] - res[j + p10[d]] + mod) % mod;
			}
		}
	}
	long long ans = 0;
	for (int j = 0; j < p10[6]; ++j)
		ans ^= (LL) j * res[j];
	cout << ans << endl;
}