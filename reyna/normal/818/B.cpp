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

const int N = (int) 105, mod = (int) 0;
int mark[N], a[N], res[N];
int main() {
	memset(res, -1, sizeof res);
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		cin >> a[j];	
		--a[j];
	}
	for (int j = 1; j < m; ++j) {
		int to = a[j] - a[j - 1];
		if (to <= 0) to += n;
		int pos = a[j - 1];
		if (res[pos] == -1) {
			res[pos] = to;
			mark[to]++;
			if (mark[to] > 1) {
				cout << -1 << endl;
				return 0;
			}
		}
		if (res[pos] != to) {
			cout << -1 << endl;
			return 0;
		}
	}
	int pt = 1;
	for (int j = 0; j < n; ++j) {
		if (res[j] == -1) {
			while (pt < n + 5 && mark[pt]) {
				++pt;
			}
			res[j] = pt;
			mark[pt] = 1;
		}
	}
	if (pt > n + 3) {
		cout << -1 << endl;
		return 0;
	}
	for (int j = 0; j < n; ++j)
		cout << res[j] << ' ';
	
}