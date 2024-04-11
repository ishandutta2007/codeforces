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
int a[N];
int main() {
	ios_base::sync_with_stdio(0);
	map<int, int> good;
	int n, k;
	cin >> n >> k;
	for (int j = 2; j * j <= k; ++j) {
		while (k % j == 0) {
			k /= j;
			good[j]++;
		}
	}
	if (k != 1) good[k]++;
	for (int j = 0; j < n; ++j) cin >> a[j];
	int sz = (int) good.size(), valid = 0;
	map<int, int> cur;
	int pt = 0;
	long long res = 0;
	for (int j = 0; j < n; ++j) {
		while ((pt < n && valid < sz) || pt <= j) {
			int x = a[pt];
			for (auto y : good) {
				int p = y.x;
				valid -= (cur[p] >= good[p]);
				while (x % p == 0) cur[p]++, x /= p;
				valid += (cur[p] >= good[p]);
			}
			++pt;
		}
		res += (valid < sz ? 0 : n - pt + 1);
		int x = a[j];
		for (auto y : good) {
			int p = y.x;
			valid -= (cur[p] >= good[p]);
			while (x % p == 0) cur[p]--, x /= p;
			valid += (cur[p] >= good[p]);
		}
	}
	cout << res << endl;
}