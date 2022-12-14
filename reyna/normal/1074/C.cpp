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
int px[N], py[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int mx_x = -1e9, mx_y = -1e9, mn_x = 1e9, mn_y = 1e9;
	for (int j = 0; j < n; ++j) {
		cin >> px[j] >> py[j];
		mx_x = max(mx_x, px[j]);
		mn_x = min(mn_x, px[j]);
		mx_y = max(mx_y, py[j]);
		mn_y = min(mn_y, py[j]);
	}
	int best_3 = 0;
	for (int c = 0; c < n; ++c) {
		int x = px[c], y = py[c];
		for (int a = 0; a <= 1; ++a)
			for (int b = 0; b <= 1; ++b) {
				int cx = (a == 0 ? mn_x : mx_x);
				int cy = (b == 0 ? mn_y : mx_y);
				best_3 = max(best_3, (abs(cx - x) + abs(cy - y)) * 2);
			}
	}
	cout << best_3 << ' ';
	for (int j = 4; j <= n; ++j) {
		cout << ((mx_x - mn_x) + (mx_y - mn_y)) * 2 << ' ';	
	}
}