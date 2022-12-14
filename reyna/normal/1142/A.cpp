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

int main() {
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	long long mn = (LL) n * k, mx = 1;
	for (int p = 0; p <= 1; ++p) {
		int cur_pos = (p == 0 ? a : k - a);
		for (int dir = 0; dir <= 1; ++dir) {
			int dis = 0;
			vector<int> all;
			for (int l = 1; l <= k; ++l) {
				int nxt = cur_pos + (dir == 0 ? -1 : 1) * l;
				while (nxt < 0) nxt += k;
				while (nxt >= k) nxt -= k;
				if (min(nxt, k - nxt) == b) {
					all.pb(l);
				}
			}
			for (int st : all) {
				if (st == 0) st += k;
				for (long long l = st; l <= (LL) n * k; l += k) {
					mn = min(mn, (LL) n * k / __gcd((LL) n * k, l));
					mx = max(mx, (LL) n * k / __gcd((LL) n * k, l));
				}
			}
		}
	}
	cout << mn << ' ' << mx << endl;
}