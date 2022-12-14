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
double px[N], py[N];
int main() {
	int n;
	double r;
	cin >> n >> r;
	for (int j = 0; j < n; ++j) {
		cin >> px[j];
		double hity = r;
		for (int i = 0; i < j; ++i) {
			double dify = 4 * r * r - (px[i] - px[j]) * (px[i] - px[j]);
			if (dify < 0) {
				continue;
			}
			hity = max(hity, py[i] + sqrt(dify));
		}
		py[j] = hity;
		cout << fixed << setprecision(10) << py[j] << ' ';
	}
	
}