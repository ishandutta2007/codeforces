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
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
	}
	int g = a[0];
	for (int j = 0; j < n; ++j)
		g = __gcd(a[j], g);
	if (g != 1) {
		cout << "YES\n";
		cout << 0 << endl;
		return 0;
	}
	int res = 0;
	for (int j = 0; j < n; ++j) {
		if (a[j] % 2 != 0) {
			int nxt = (j + 1 == n ? 0 : a[j + 1] % 2);
			if (nxt) {
				res += 1;
			} else {
				res += 2;
			}
			a[j + 1] = 0;
		}
	}
	cout << "YES" << endl;
	cout << res << endl;
}