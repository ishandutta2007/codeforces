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
int n;
int get_val(int x) {
	cout << "? " << x + 1 << endl;
	int p;
	cin >> p;
	cout << "? " << x + n / 2 + 1 << endl;
	int q;
	cin >> q;
	return p - q;
}
int main() {
	cin >> n;
	if ((n >> 1) & 1) {
		cout << "! -1" << endl;
		return 0;
	}
	int f = get_val(0);
	if (f == 0) {
		cout << "! " << 1 << endl;
		return 0;
	}
	int bl = 0, br = n / 2;
	while (bl < br - 1) {
		int bm = bl + br >> 1;
		int x = get_val(bm);
		if (x == 0) {
			cout << "! " << bm + 1 << endl;
			return 0;
		}
		if ((x < 0 && f < 0) || (x > 0 && f > 0)) {
			bl = bm;
		} else {
			br = bm;
		}
	}	
	assert(0);
	
}