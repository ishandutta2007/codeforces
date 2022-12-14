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

const int N = (int) 2e5 + 5, mod = (int) 0;
int a[N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) {
		cin >> a[j + 1];
		a[j + 1] ^= a[j];
	}
	map<int, int> cnt;
	for (int j = 0; j <= n; ++j) {
		int x = a[j];
		int dual = a[j] ^ ((1 << k) - 1);
		cnt[min(x, dual)]++;
	}
	long long res = (LL) n * (n + 1) / 2;
	for (auto x : cnt) {
		int c = x.second;
		int h0 = c / 2;
		int h1 = c - h0;
		res -= (LL) h0 * (h0 - 1) / 2;
		res -= (LL) h1 * (h1 - 1) / 2;
	}
	cout << res << endl;
}