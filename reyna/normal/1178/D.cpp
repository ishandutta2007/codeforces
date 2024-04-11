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

const int N = (int) 3e5 + 5, mod = (int) 0;

int is_prime(int x) {
	if (x == 1) return 0;
	for (int j = 2; j * j <= x; ++j)
		if (x % j == 0)
			return 0;
	return 1;
}

int main() {
	int n;
	cin >> n;
	if (n == 3) {
		cout << 3 << endl;
		cout << 1 << ' ' << 2 << endl;
		cout << 2 << ' ' << 3 << endl;
		cout << 1 << ' ' << 3 << endl;
		return 0;
	}
	for (int inc = 0; inc <= n / 2; ++inc) {
		if (is_prime(n + inc)) {
			cout << n + inc << '\n';
			for (int j = 0; j < n - 1; ++j) {
				cout << j + 1 << ' ' << j + 2 << '\n';
			}
			cout << n << ' ' << 1 << '\n';
			for (int j = 0; j < inc; ++j) {
				cout << j + 1 << ' ' << j + 1 + n / 2 << '\n';	
			}
			return 0;
		}
	}
}