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

const int N = (int) 1e3 + 3, mod = (int) 0;
int a[N], bg, ed;
int main() {
	int n, m, c;
	cin >> n >> m >> c;
	ed = n - 1;
	while (m--) {
		int x;
		cin >> x;
		int pt = 0;
		if (x <= c / 2) {
			pt = 0;
			while (pt < bg && a[pt] <= x) {
				++pt;
			}
			a[pt] = x;
			bg = max(bg, pt + 1);
		} else {
			pt = n - 1;
			while (pt > ed && a[pt] >= x) {
				--pt;	
			}
			a[pt] = x;
			ed = min(ed, pt - 1);
		}
		cout << pt + 1 << endl;
		if (bg == ed + 1) {
			return 0;	
		}
	}
}