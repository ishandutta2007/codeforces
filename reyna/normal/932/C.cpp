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
	ios_base::sync_with_stdio(0);
	int n, a, b;
	cin >> n >> a >> b;
	for (int ja = 0; ja * a <= n; ++ja) {
		if ((n - ja * a) % b == 0) {
			int jb = (n - ja * a) / b;
			int cnt = 1;
			for (int i = 0; i < ja; ++i) {
				cout << cnt + a - 1 << ' ';
				for (int j = 0; j < a - 1; ++j) {
					cout << cnt + j << ' ';
				}
				cnt += a;
			}
			for (int i = 0; i < jb; ++i) {
				cout << cnt + b - 1 << ' ';
				for (int j = 0; j < b - 1; ++j) {
					cout << cnt + j << ' ';
				}
				cnt += b;
			}
			return 0;
		}
	}
	cout << -1 << endl;
}