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
int m, a, b, vis[N], seen = 1;
void go(int x, int reach) {
	if (vis[x]) return;
	vis[x] = 1;	
	++seen;
	if (x - b >= 0)
		go(x - b, reach);
	if (x + a <= reach)
		go(x + a, reach);
}
int32_t main() {
	cin >> m >> a >> b;
	int g = __gcd(a, b);
	vis[0] = 1;
	int res = 0;
	for (int x = 1; x <= min(m, N - 1); ++x) {
		if (x >= a) {
			if (vis[x - a]) go(x, x);
		}
		res += seen;
		res -= x / g + 1;
	}
	int last = m / g * g;
	res += (m - last + 1) * (m / g + 1);
	res += (m / g + 1) * (m / g) / 2 * g;
	cout << res << endl;
	
}