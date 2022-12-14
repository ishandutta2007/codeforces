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
#define int long long
const int N = (int) 0, mod = (int) 0;
int check(int l, int r) {
	--r;
	cout << l << ' ' << r << endl;
	string ans;
	cin >> ans;
	if (l == r && ans == "Yes") {
		exit(0);
	}
	if (ans == "Yes") {
		return 1;
	}
	return 0;
}
int32_t main() {
	srand(time(0));
	int n, k;
	cin >> n >> k;
	int bl = 1, br = n + 1;
	while (true) {
		int bm = bl + br >> 1;
		if (br - bl > 42) {
			if (check(bl, bm)) {
				bl = max(bl - k, 1LL);
				br = min(n + 1, bm + k);
			} else {
				bl = max(bm - k, 1LL);
				br = min(n + 1, br + k);
			}
		} else {
			int pos = bl + (rand() | (rand() << 16)) % (br - bl);
			check(pos, pos + 1);
			bl = max(bl - k, 1LL);
			br = min(n + 1, br + k);
		}
	}
}