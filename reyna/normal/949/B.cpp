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
#define int long long
const int N = (int) 0, mod = (int) 0;
int f(int n, int pos) {
	if (n == 1) {
		return pos;
	}
	if (pos % 2 == 0) {
		return pos / 2;
	}
	if (n % 2 == 0) {
		return n / 2 + f(n / 2, pos / 2);
	} else {
		if (pos == 1) {
			return n / 2 + 1 + f(n / 2, n / 2 - 1);
		} else {
			return n / 2 + 1 + f(n / 2, (pos - 2) / 2);
		}
	}
}
int32_t main() {
	long long n, q;
	cin >> n >> q;
	while (q--) {
		int pos;
		cin >> pos;
		--pos;
		cout << f(n, pos) + 1 << '\n';
	}
}