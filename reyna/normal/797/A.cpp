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
	int n, k;
	cin >> n >> k;
	vector<int> a;
	for (int j = 2; j <= n; ++j) {
		while (n % j == 0) {
			a.pb(j);
			n /= j;
		}
	}
	if (SZ(a) < k) {
		cout << -1 << endl;
		return 0;
	}
	while (SZ(a) != k) {
		int x = a[SZ(a) - 1] * a[SZ(a) - 2];
		a.pop_back();
		a.pop_back();
		a.pb(x);
	}
	for (int x : a) cout << x << ' ';
}