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
int n, mark[N], val[N], cl[N], cr[N], root, sr[N];
int solve(int v, int b, int e) {
	if (e - b <= 0) return 0;
	if (v == -1) return e - b;
	int ml = lower_bound(sr + b, sr + e, val[v]) - sr;
	int mr = upper_bound(sr + b, sr + e, val[v]) - sr;
	return solve(cl[v], b, ml) + solve(cr[v], mr, e);
}
int main() {
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> val[j] >> cl[j] >> cr[j];
		if (cl[j] >= 0) cl[j]--, mark[cl[j]] = 1;
		if (cr[j] >= 0) cr[j]--, mark[cr[j]] = 1;
		sr[j] = val[j];
	}
	sort(sr, sr + n);
	for (int j = 0; j < n; ++j)
		if (!mark[j])
			root = j;
	cout << solve(root, 0, n) << endl;
}