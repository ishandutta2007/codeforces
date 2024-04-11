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
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int pt = 0;
	for (int j = 1; j <= 2 * n; ++j)
		if (j % 4 == 0) {
			a[pt] = j;
			a[pt + n] = j - 1;
			++pt;
		} else if (j % 4 == 1) {
			a[pt] = j;
			a[pt + n] = j + 1;
			++pt;
		}
	pt *= 2;
	for (int j = 0; j < pt; ++j)
		cout << a[j] << ' ';
	
}