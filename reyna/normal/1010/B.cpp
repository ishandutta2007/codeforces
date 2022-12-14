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
int sv[66];
int main() {
	int n, m;
	cin >> m >> n;
	for (int j = 0; j < n; ++j) {
		cout << 1 << endl;
		cin >> sv[j];
		if (sv[j] == 0) {
			return 0;
		}
	}
	int cnt = 0;
	int bl = 1, br = m + 1;
	while (br - bl > 1) {
		int bm = bl + br >> 1;
		cout << bm << endl;
		int x;
		cin >> x;
		x *= sv[cnt];
		cnt = (cnt + 1) % n;
		if (x == 0) {
			return 0;
		}
		if (x == -1) {
			br = bm;	
		} else {
			bl = bm;
		}
	}
}