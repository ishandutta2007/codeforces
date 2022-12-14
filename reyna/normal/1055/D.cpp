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

const int N = (int) 3005, mod = (int) 1e9 + 7, base = 727;
string a[N], b[N];
int xl[N], xr[N];
int main() {
	ios_base::sync_with_stdio(0);
	memset(xl, -1, sizeof xl);
	memset(xr, -1, sizeof xr);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) cin >> b[j];
	for (int v = 0; v < n; ++v) {
		int m = (int) a[v].size();
		for (int j = 0; j < m; ++j)
			if (a[v][j] != b[v][j]) {
				if (xl[v] == -1) xl[v] = j;
				xr[v] = j + 1;
			}
	}
	int fst = -1;
	for (int v = 0; v < n; ++v) {
		if (xl[v] != -1) {
			fst = v;
		}
	}
	if (fst == -1) {
		cout << "YES\n";
		string s = "", t = "";
		for (int j = 0; j < N; ++j) s += 'a', t += 'b';
		cout << s << endl << t << endl;
		return 0;
	}
	for (int v = 0; v < n; ++v) {
		if (xl[v] >= 0) {
			if (xr[v] - xl[v] != xr[fst] - xl[fst]) {
				cout << "NO\n";
				return 0;
			}
			for (int j = 0; j < xr[v] - xl[v]; ++j)
				if (a[v][j + xl[v]] != a[fst][j + xl[fst]] || b[v][j + xl[v]] != b[fst][j + xl[fst]]) {
					cout << "NO\n";
					return 0;
				}
		}
	}
	while (xl[fst] >= 1) {
		char cx = a[fst][xl[fst] - 1], cy = b[fst][xl[fst] - 1];
		int can = 1;
		for (int v = 0; v < n; ++v) if (xl[v] >= 0) {
			if (xl[v] == 0) {
				can = 0;
			} else {
				if (a[v][xl[v] - 1] != cx || b[v][xl[v] - 1] != cy) {
					can = 0;
				}
			}
		}
		if (!can) break;
		for (int v = 0; v < n; ++v) if (xl[v] >= 0) --xl[v];
	}
	while (xr[fst] < (int) a[fst].size()) {
		char cx = a[fst][xr[fst]], cy = b[fst][xr[fst]];
		int can = 1;
		for (int v = 0; v < n; ++v) if (xl[v] >= 0) {
			if (xr[v] == (int) a[v].size()) {
				can = 0;
			} else {
				if (a[v][xr[v]] != cx || b[v][xr[v]] != cy) {
					can = 0;
				}
			}
		}
		if (!can) break;
		for (int v = 0; v < n; ++v) if (xl[v] >= 0) ++xr[v];
	}
	int pw = 1;
	for (int j = 0; j < xr[fst] - xl[fst]; ++j) pw = (LL) pw * base % mod;
	int fh = 0;
	for (int j = xl[fst]; j < xr[fst]; ++j) {
		fh = (LL) fh * base % mod;
		fh = (fh + a[fst][j]) % mod;
	}
	for (int v = 0; v < n; ++v) {
		int curh = 0;
		for (int j = 0; j < (int) a[v].size(); ++j) {
			curh = (LL) curh * base % mod;
			curh = (curh + a[v][j]) % mod;
			if (j >= xr[fst] - xl[fst])
				curh = (curh - (LL) pw * a[v][j - (xr[fst] - xl[fst])] % mod + mod) % mod;
			if (curh == fh && xl[v] == -1) {
				cout << "NO\n";
				return 0;
			}
			if (curh == fh && j != xr[v] - 1) {
				cout << "NO\n";
				return 0;
			}
			if (curh == fh) break;
		}
	}
	cout << "YES\n";
	for (int j = xl[fst]; j < xr[fst]; ++j) cout << a[fst][j];
	cout << endl;
	for (int j = xl[fst]; j < xr[fst]; ++j) cout << b[fst][j];
	cout << endl;
}