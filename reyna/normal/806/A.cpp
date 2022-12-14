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

const int N = (int) 0, mod = (int) 0;
#define int long long
int32_t main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		int bl = -1, br = 2e9 + 10;
		while (bl < br - 1) {
			int bm = bl + br >> 1;
			int gox = p * bm, goy = q * bm;
			if (gox - x <= goy - y && goy >= y && gox >= x) {
				br = bm;
			} else {
				bl = bm;
			}
		}
		if (br > 2e9) {
			cout << -1 << endl;	
		} else {
			cout << br * q - y << endl;
		}
	}
}