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
	int n, m;
	cin >> n >> m;
	int h = 0, t = m;
	for (int j = 0; j < m; ++j) {
		if (~j & 1) {
			a[j] = h++;	
		} else {
			a[j] = --t;
		}
	}
	for (int cur = 0; cur < n * m; ++cur) {
		int id = cur / 2;
		int x = id / m;
		int y = id % m;//a[id % m];
		if ((n & 1) && cur >= (n - 1) * m) {
			cout << n / 2 + 1 << ' ' << a[cur % m] + 1 << '\n';	
			continue;
		}
		if (cur & 1) {
			cout << n - x << ' ' << m - y << '\n';	
		} else {
			cout << x + 1 << ' ' << y + 1 << '\n';
		}
		
	}
}