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
#define int long long
const int N = (int) 2005, mod = (int) 0;
int a[N], res[N];
int32_t main() {
	long long p, t = 0, k;
	cin >> p >> k;
	a[t] = -(p / k);
	res[t] = p + a[t] * k;
	t++;
	while (true) {
		if (a[t - 1] == 0) {
			break;
		}
		if (a[t - 1] < 0) {
			a[t] = (-a[t - 1] + k - 1) / k;
			res[t] = a[t - 1] + a[t] * k;
			t++;	
		} else {
			a[t] = -(a[t - 1] / k);
			res[t] = a[t - 1] + a[t] * k;
			t++;
		}
	}
	--t;
	if (!t) {
		
		cout << 1 << '\n' << p << endl;
		return 0;
	}
	res[t] = a[t - 1];
	cout << t + 1 << endl;
	for (int j = 0; j < t + 1; ++j) {
		cout << res[j] << ' ';
	}
}