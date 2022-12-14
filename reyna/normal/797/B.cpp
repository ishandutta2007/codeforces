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
int a[N];
int main() {
	int n, m = 0, add = 0;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		if (abs(x) % 2 == 0) {
			if (x >= 0) {
				add += x;
			}
		} else {
			a[m++] = x;
		}
	}
	sort(a, a + m);
	int sum = 0, res = -2e9;
	for (int j = m - 1; j >= 0; --j) {
		sum += a[j];
		if ((m - j) & 1) res = max(res, sum + add);
	}
	cout << res << endl;
}