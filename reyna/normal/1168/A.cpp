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
int n, m, a[N];
int check(int lim) {
	int last = 0;
	for (int j = 0; j < n; ++j) {
		int cur = a[j];
		if (a[j] < last) {
			if (a[j] + lim >= last) {
				continue;	
			}
			return 0;
		}
		if (a[j] + lim >= last + m) {
			continue;
		}
		last = cur;
	}
	return 1;
}
int main() {
	cin >> n >> m;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int bl = -1, br = m;
	while (bl < br - 1) {
		int bm = bl + br >> 1;	
		if (check(bm)) {
			br = bm;	
		} else {
			bl = bm;
		}
	}
	cout << br << endl;
}