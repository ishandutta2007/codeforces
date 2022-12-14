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
#define double long double
typedef long long LL;
typedef pair<double, double> point;
const int N = (int) 1005, mod = (int) 0;
point p[N];
point operator - (point a, point b) { return point(a.x - b.x, a.y - b.y); }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
double cross(point x, point y, point z) {
	return cross(y - x, z - x);
}
double dist(point a) { return sqrt(a.x * a.x + a.y * a.y); }
int main() {
	int n;
	cin >> n;
	double res = 1e18;
	for (int j = 0; j < n; ++j) {
		int x, y;
		cin >> x >> y;
		p[j] = point(x, y);
	}
	for (int j = 0; j < n; ++j) {
		int pr = (j - 1 + n) % n, cur = j, nx = (j + 1) % n;
		res = min(res, abs(cross(p[cur], p[nx], p[pr])) / dist(p[nx] - p[pr]) / 2);
	}
	cout << setprecision(10) << fixed << res << endl;
}