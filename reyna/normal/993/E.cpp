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

const int N = (int) (1 << 19), lg = 19, mod = (int) 0;
typedef pair<double, double> point;

#define real first
#define imag second

inline point operator -(const point &a, const point &b) { return point(a.real - b.real, a.imag - b.imag); }
inline point operator +(const point &a, const point &b) { return point(a.real + b.real, a.imag + b.imag); }
inline point operator *(const point &a, const point &b) { return point(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real); }
int rev[N], sum[N];
void FFT(point a[], bool inverse) {
	for (int i = 0; i < N; ++i)
		if (rev[i] > i)
			swap(a[rev[i]], a[i]);
	double arg = acos(-1.0);
	for (int len = 2; len <= N; len <<= 1, arg /= 2) {
		point wn = point(cos(arg), inverse == 0? sin(arg): -sin(arg));
		for (int j = 0; j < N; j += len) {
			point w = point(1, 0);
			for (int x = j, y = j + len / 2; y < j + len; ++x, ++y) {
				point u = a[x], v = a[y] * w;
				a[x] = u + v;
				a[y] = u - v;
				w = w * wn;
			}
		}
	}
	if (inverse)
		for (int i = 0; i < N; ++i)
			a[i].real /= N, a[i].imag /= N;
}


point a[N], b[N];

void gen(int bit = lg - 1, int x = 0, int y = 0) {
	if (bit == -1) {
		rev[y] = x;
		return;
	}
	gen(bit - 1, x, y);
	gen(bit - 1, x + (1 << bit), y + (1 << lg - bit - 1));
}
int main() {
	int n, x;
	cin >> n >> x;
	for (int j = 0; j < n; ++j) {
		int y;
		cin >> y;
		sum[j + 1] = sum[j] + (y < x);
	}
	int pt = 0;
	long long res0 = 0;
	for (int j = 0; j <= n; ++j) {
		pt = max(pt, j);
		while (pt <= n && sum[pt] == sum[j]) ++pt;
		res0 += pt - j - 1;
	}
	for (int j = 0; j <= n; ++j) {
		a[sum[j]].real += 1;
		b[n - sum[j]].real += 1;	
	}
	gen();
	FFT(a, false);
	FFT(b, false);
	for (int j = 0; j < N; ++j) a[j] = a[j] * b[j];
	FFT(a, true);
	cout << res0 << ' ';
	for (int j = n + 1; j <= n + n; ++j)
		cout << (long long) (a[j].real + 0.5) << ' ';



}