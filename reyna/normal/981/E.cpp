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
const int N = (int) 1e4 + 4, mod = (int) (1 << 23) * 17 * 7 + 1;
int produce[N], ways[N], ql[N], qr[N], qv[N];
vector<int> op[N], cl[N];
int main() {
	int n, q;
	cin >> n >> q;
	for (int j = 0; j < q; ++j) {
		int &xl = ql[j], &xr = qr[j], &xv = qv[j];
		cin >> xl >> xr >> xv;
		--xl;
		op[xl].push_back(j);
		cl[xr].push_back(j);
	}
	ways[0] = produce[0] = 1;
	for (int j = 0; j < n; ++j) {
		for (int id : op[j]) {
			int val = qv[id];
			for (int i = n; i >= val; --i) {
				ways[i] += ways[i - val];
				if (ways[i] >= mod) {
					ways[i] -= mod;	
				}
			}
		}
		for (int id : cl[j]) {
			int val = qv[id];
			for (int i = 0; i + val <= n; ++i) {
				ways[i + val] -= ways[i];
				if (ways[i + val] < 0) {
					ways[i + val] += mod;	
				}
			}
		}
		for (int i = 0; i <= n; ++i) {
			produce[i] |= (ways[i] != 0);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) cnt += produce[i];
	cout << cnt << '\n';
	for (int j = 1; j <= n; ++j)
		if (produce[j])
			cout << j << ' ';
}