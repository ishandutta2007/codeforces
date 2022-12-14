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

const int N = (int) 1e6 + 5, mod = (int) 0;
int n, a[N], b[N], cnt[N];
int check(int lim) {
	memset(cnt, 0, sizeof cnt);
	if (lim < n) {
		for (int j = 0; j < n; ++j) if (a[j] != -1) cnt[a[j]]++;
		for (int j = lim; j < n; ++j)
			if (b[j] != j - lim)
				return 0;
		int pt = 0;
		for (int j = n - lim; j < n; ++j) {
			if (!cnt[j]) {
				return 0;	
			}
			cnt[b[pt++]] = 1;
		}
		return 1;
	}
	for (int j = 0; j < n; ++j) if (a[j] != -1) cnt[a[j]]++;
	for (int j = 0; j < min(n, lim - n); ++j) cnt[b[j]]++;
	int pt = min(n, lim - n);
	for (int j = 0; j < n; ++j) {
		if (!cnt[j]) return 0;
		if (pt < n) cnt[b[pt]]++, ++pt;	
	}
	return 1;
	
}
int main() {
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], --a[j];
	for (int j = 0; j < n; ++j) cin >> b[j], --b[j];
	for (int j = 0; j < n; ++j)
		if (b[j] == 0) {
			if (check(j)) {
				cout << j << endl;
				return 0;
			}
		}
	int bl = n - 1, br = 2 * n + 1;
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