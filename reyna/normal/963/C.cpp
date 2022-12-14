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
const int N = (int) 1e6 + 6, mod = (int) 0;
int n, w[N], h[N], c[N];
map<pair<int, int>, int> cnt;
map<int, int> value;
set<int> wx, hs;
map<int, int> sumh, sumw;
void ex() {
	cout << 0 << endl;
	exit(0);
}
int mul(int x, int y) {
	if ((double) x * (double) y > 1e15) {
		ex();
	}
	return x * y;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int g = 0, sumall = 0;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> h[i] >> c[i];
		wx.insert(w[i]);
		hs.insert(h[i]);
		cnt[mp(w[i], h[i])] = c[i];	
		sumall += c[i];
	}
	for (int x : wx) {
		int s = 0;
		for (int y : hs) { s += cnt[mp(x, y)]; 
			if (cnt[mp(x, y)] == 0) {
				cout << 0 << endl;
				return 0;
			}
		}
		
		if (g == 0) {
			g = s;
		} else {
			g = __gcd(s, g);
		}
	}
	for (int x : wx) for (int y : hs) sumw[x] += cnt[mp(x, y)], sumh[y] += cnt[mp(x, y)];
	int gy = 0;
	for (int y : hs) gy = (gy == 0 ? sumh[y] : __gcd(gy, sumh[y]));
	int ss = 0;
	for (int i = 0; i < n; ++i) {
/*		int wv = g;
		if (c[i] % wv != 0) {
			cout << 0 << endl;
			return 0;
		}
		int wu = sumh[h[i]] / wv;
		if (value[h[i]] == 0) {
			value[h[i]] = wu;
		} else if (value[h[i]] != wu) {
			cout << 0 << endl;
			return 0;
		}	
		*/
		int x = mul(sumh[h[i]] / gy, sumw[w[i]] / g);
		if (c[i] % x != 0) {
			ex();	
		}
		if (ss == 0) {
			ss = c[i] / x;
		}
		if (c[i] / x != ss) ex();
		
	} 
	g = ss;
	int res = 0;
	for (int i = 1; i * i <= g; ++i) {
		if (g % i == 0) {
			res += 1;
			if (g / i != i)
				res += 1;
		}
	}
		
	cout << res << endl;
	
}