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
vector<int> dv;
int main() {
	int n;
	cin >> n;
	for (int j = 2; j * j <= n; ++j) {
		if (n % j == 0) {
			dv.push_back(j);	
		}
	}
	if (!dv.size()) {
		cout << "NO\n";
		return 0;
	}
	int x = dv[0], z = 1;
	int y = n;
	while (y % x == 0) {
		y /= x;
		z *= x;
	}
	x = z;
	if (y < x) swap(x, y);
	if (x == 1) {
		cout << "NO\n";
		return 0;
	}
//	cout << x << ' ' << y << endl;
	for (int j = 1; j < x; ++j) {
		long long val = y * (LL) j;
		if (val < n) {
			long long need = n - val - 1;
			if (need % x == 0) {
				long long use = need / x;	
				cout << "YES\n";
				cout << 2 << '\n';
				cout << j << ' ' << x << '\n';
				cout << use << ' ' << y << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
	
}