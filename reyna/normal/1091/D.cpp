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

const int N = (int) 1e6 + 6, mod = (int) 998244353;
int inv[N], f[N];
int pw(int a, int b) { 
	if (b == 0) return 1;
	return pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod;
}
int main() {
	f[0] = inv[0] = 1;
	for (int j = 1; j < N; ++j) f[j] = (LL) f[j - 1] * j % mod, inv[j] = pw(f[j], mod - 2);
	int n;
	cin >> n;
	int res = f[n];
	for (int len = 1; len < n; ++len) {
		res = (res + (n - len - 1) * (LL) f[n] % mod * inv[len + 1] % mod * len % mod + mod) % mod;
	}
	cout << (res) % mod << endl;
}