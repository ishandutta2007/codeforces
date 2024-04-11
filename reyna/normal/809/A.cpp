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
int p2[N], a[N];
int main() {
	p2[0] = 1;
	for (int j = 1; j < N; ++j)
		p2[j] = (p2[j - 1] + p2[j - 1]) % mod;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> a[j];
	sort(a, a + n);
	long long res = 0;
	for (int j = 0; j < n; ++j) {
		res = (res + (LL) a[j] * p2[j]) % mod;
		res = (res - (LL) a[j] * p2[n - j - 1] % mod + mod) % mod;
	}
	cout << res << endl;
}