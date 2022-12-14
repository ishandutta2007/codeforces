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

const int N = (int) 1e5 + 5, mod = (int) 0;
int a[N], pre[N], suf[N], lis[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		int l, r;
		cin >> l >> r;
		--l;
		a[l]++;
		a[r]--;
	}
	for (int j = 0; j < m; ++j) {
		if (j) a[j] += a[j - 1];
	}
	memset(lis, 63, sizeof lis);
	int sz = 0;
	for (int j = 0; j < m; ++j) {
		int pos = upper_bound(lis, lis + sz, a[j]) - lis;
		lis[pos] = a[j];
		sz = max(sz, pos + 1);
		pre[j] = sz;
	}
	memset(lis, 63, sizeof lis);
	sz = 0;
	for (int j = m - 1; j >= 0; --j) {
		int pos = upper_bound(lis, lis + sz, a[j]) - lis;
		lis[pos] = a[j];
		sz = max(sz, pos + 1);
		suf[j] = sz;
	}
	int res = suf[0];
	for (int j = 0; j < m; ++j)
		res = max(res, pre[j] + suf[j + 1]);
	cout << res << endl;
}