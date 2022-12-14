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
	int n, h;
	cin >> n >> h;
	double area = (double) h / 2 / n, cur = 0;
	for (int j = 0; j < n - 1; ++j) {
		double bl = 0, br = h;
		double use = 0;
		for (int i = 0; i < 200; ++i) {
			double bm = (bl + br) / 2;
			double base = (bm / h);
			double cur_area = base * bm / 2;
			if (cur_area - cur >= area) {
				br = bm;
				use = cur_area;
			} else {
				bl = bm;
			}
		}
		cur = use;
		cout << setprecision(10) << fixed <<  br << ' ';
	}
}