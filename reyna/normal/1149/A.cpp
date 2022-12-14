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

const int N = (int) 2e5 + 5, mod = (int) 0;

int main() {
	int n, cnt0 = 0, cnt1 = 0;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		if (x == 1) ++cnt0;
		else ++cnt1;
	}
	if (cnt0 == 0) {
		for (int j = 0; j < n; ++j)
			cout << 2 << ' ';
		cout << endl;
		return 0;
	}
	if (cnt1 == 0) {
		for (int j = 0; j < n; ++j)
			cout << 1 << ' ';
		cout << endl;
		return 0;
	}
	cout << 2 << ' ' << 1 << ' ';
	--cnt0;
	--cnt1;
	int o = cnt0 & 1;
	for (int j = 2; j < n - o; ++j) {
		if (cnt0 > o) {
			cout << 1 << ' ';
			--cnt0;
		} else {
			cout << 2 << ' ';
			--cnt1;
		}
	}
	if (cnt0) cout << 1 << ' ';
	
	cout << endl;
	
}