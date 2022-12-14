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

typedef pair<double, double> point;

#define real first
#define imag second

inline point operator -(const point &a, const point &b) { return point(a.real - b.real, a.imag - b.imag); }
inline point operator +(const point &a, const point &b) { return point(a.real + b.real, a.imag + b.imag); }
inline point operator *(const point &a, const point &b) { return point(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real); }
void FFT(point a[], int lg, bool inverse) {
	int n = 1 << lg;
	for (int j = 0; j < n; ++j) {
		int rev = 0;
		for (int b = 0; b < lg; ++b)
			rev |= (j >> b & 1) << (lg - b - 1);
		if (j > rev) swap(a[rev], a[j]);
	}
	double arg = acos(-1.0);
	for (int len = 2; len <= n; len <<= 1, arg /= 2) {
		point wn = point(cos(arg), inverse == 0? sin(arg): -sin(arg));
		for (int j = 0; j < n; j += len) {
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
		for (int j = 0; j < n; ++j)
			a[j].real /= n, a[j].imag /= n;
}
const int N = (int) 2e6 + 6, M = (1 << 20) + 100, mod = (int) 0;
int res[N], mark[N];
vector<int> dv[N];
point a[N], b[N];
int main() {
	ios_base::sync_with_stdio(0);
	for (int j = 1; j < M; ++j)
		for (int p = j; p < M; p += j)
			dv[p].push_back(j);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int lg = 0;
		while ((1 << lg) < 2 * n) ++lg;
		string s;
		cin >> s;
		for (int period = 1; period <= 2 * n; ++period) res[period] = 1, mark[period] = 0;
		for (int turn = 0; turn <= 0; ++turn) {
			for (int j = 0; j < (1 << lg); ++j) {
				a[j] = b[j] = point(0, 0);
				mark[j] = 0;
			}
			for (int j = 0; j < n; ++j) {
				int pos = j;
				if (s[j] == 'V') {
					a[pos] = point(1, 0);	
				} else if (s[j] == 'K') {
					b[n - pos - 1] = point(1, 0);
				}
			}
			FFT(a, lg, false);
			FFT(b, lg, false);
			for (int j = 0; j < (1 << lg); ++j) a[j] = a[j] * b[j];
			FFT(a, lg, true);
			for (int pos = 0; pos < (1 << lg); ++pos) {
				int val = (a[pos].first < 0.5);
				if (!val) {
					int cur = abs(pos - (n - 1));
			//		if (cur == 0) continue;
					if (res[cur]) {
						for (int x : dv[cur]) res[x] = 0;
					}
					res[cur] = 0;
				}
			}
			for (int j = 0; j < n; ++j) {
				if (s[j] == 'V') {
					s[j] = 'K';
				} else if (s[j] == 'K') {
					s[j] = 'V';
				}
			}
		}
		int cnt = 0;
		for (int j = 1; j <= n; ++j) cnt += res[j];
		cout << cnt << '\n';
		for (int j = 1; j <= n; ++j) if (res[j]) cout << j << ' ';
		cout << '\n';
	}
}