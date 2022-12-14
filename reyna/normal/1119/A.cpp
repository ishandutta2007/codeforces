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
int mark[N], fs[N], ls[N], a[N];
int main() {
	vector<int> imp;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j], --a[j];
	for (int j = 0; j < n; ++j) fs[j] = ls[j] = -1;
	{
	memset(mark, 0, sizeof mark);
	int cnt = 0;
	for (int j = 0; j < n; ++j) {
		if (!mark[a[j]]) {
			++cnt;
			if (cnt < 10) imp.push_back(a[j]);
			fs[a[j]] = j;
			mark[a[j]] = 1;
		}
	}
	}
	{
	memset(mark, 0, sizeof mark);
	int cnt = 0;
	for (int j = n - 1; j >= 0; --j) {
		if (!mark[a[j]]) {
			++cnt;
			if (cnt < 10) imp.push_back(a[j]);
			ls[a[j]] = j;
			mark[a[j]] = 1;
		}
	}
	}
	int res = 0;
	for (int x : imp)
		for (int y : imp)
			if (x != y) {
				res = max(res, ls[y] - fs[x]);	
			}
	cout << res << endl;
}