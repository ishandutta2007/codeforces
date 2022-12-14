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
int n, px[N][2], py[N][2], res[N], pre[N], suf[N];
void solve(int a[N][2], int m, int cntx, int cnty) {
	memset(pre, 0, sizeof pre);
	memset(suf, 0, sizeof suf);
	for (int j = 0; j < n; ++j) {
		if (a[j][0] > a[j][1]) swap(a[j][0], a[j][1]);
		pre[a[j][0]]++;
		suf[a[j][1]]++;
	}
	for (int j = 1; j <= m; ++j) pre[j] += pre[j - 1];
	for (int j = m; j >= 0; --j) suf[j] += suf[j + 1];
	for (int j = 0; j < n; ++j) {
		res[j] &= (cntx == pre[a[j][1] - 1] - (a[j][0] == a[j][1] - 1));
		res[j] &= (cnty == suf[a[j][0] + 1] - (a[j][1] == a[j][0] + 1));
	}
}
int main() {
	for (int j = 0; j < N; ++j) res[j] = 1;
	int r, c;
	cin >> n >> r >> c;
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < 2; ++i) {
			cin >> px[j][i] >> py[j][i];
		}
	int cntl, cntr, cntt, cntb;
	cin >> cntl >> cntr >> cntt >> cntb;
	solve(px, r + 1, cntl, cntr);
	solve(py, c + 1, cntt, cntb);
	int flag = 0;	
	for (int j = 0; j < n; ++j)
		if (res[j]) {
			cout << j + 1 << endl;
			flag = 1;
		}
	if (!flag) cout << -1 << endl;
	
	
}