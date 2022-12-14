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
const int N = (int) 70, mod = (int) 0;
int jump[N];
int geth(int x) {
	int res = 0;
	while (x) x >>= 1, ++res;	
	return res - 1;
}
int32_t main() {
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, k;
			cin >> x >> k;
			int h = geth(x);
			jump[h] += k;
			jump[h] %= 1ll << h;
			if (jump[h] < 0) jump[h] += 1ll << h;
		} else if (t == 2) {
			int x, k;
			cin >> x >> k;
			int h = geth(x);
			k %= 1ll << h;
			if (k < 0) k += 1ll << h;
			for (int j = h; j < 63; ++j) {
				jump[j] = (jump[j] + k) % (1ll << j);
				k <<= 1;	
			}
		} else {
			int x;
			cin >> x;
			int h = geth(x);
			while (h) {
				cout << x << ' ';
				int shiftedx = (1ll << h) + (x + jump[h]) % (1ll << h);
				int par = shiftedx >> 1;
				int nxt = (1ll << h - 1) + (par - jump[h - 1] + (1ll << h - 1)) % (1ll << h - 1);
			//	cout << " hey " << x << ' ' << shiftedx << ' ' << par << ' ' << nxt << ' ' << jump[h] << ' ' << jump[h - 1] << endl;
				x = nxt;
				--h;
			}
			cout << x << '\n';
		}
	}
}