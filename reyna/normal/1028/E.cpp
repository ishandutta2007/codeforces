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
long long a[N];
int main() {
	int n;
	cin >> n;
	long long mx = 0;
	for (int j = 0; j < n; ++j)
		cin >> a[j], mx = max(mx, a[j]);
	for (int j = 0; j < n; ++j) {
		int pr = (j + n - 1) % n;
		if (a[pr] != mx && a[j] == mx) {
			cout << "YES\n";
			for (int cur = (j + n - 1) % n, i = 0; i < n - 1; ++i, cur = (cur + n - 1) % n) {
				a[cur] += a[(cur + 1) % n] * (i == 0 ? 2 : 1);	
			}
			for (int i = 0; i < n; ++i)
				cout << a[i] << ' ';
			return 0;
		}
	}
	if (mx == 0) {
		cout << "YES\n";
		for (int j = 0; j < n; ++j)
			cout << 1 << ' ';
		return 0;
	}
	cout << "NO\n";
}