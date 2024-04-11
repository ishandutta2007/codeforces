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

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], lf[N], rg[N];
int main() {
	int n, k;
	cin >> n >> k;
	for (int j = 0; j < n; ++j) lf[j] = k, rg[j] = -1;
	for (int j = 0; j < k; ++j) {
		cin >> a[j];
		--a[j];
	}
	int res = 0;
	for (int j = k - 1; j >= 0; --j) lf[a[j]] = j;
	for (int j = 0; j < k; ++j) rg[a[j]] = j;
	for (int cur = 0; cur < n; ++cur) {
		for (int ot = max(0, cur - 1); ot <= min(n - 1, cur + 1); ++ot) {
			if (ot == cur) {
				res += (rg[cur] == -1);
			} else {
				int xl = lf[cur];
				int xr = rg[ot];
				if (xr < xl) {
					res++;	
				}
			}
		}
	}
	cout << res << endl;
}