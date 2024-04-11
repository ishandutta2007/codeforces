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
const int N = 1e6 + 6, mod = (int) 0;

long long get_num(int x0, int x1, int x2) {
	return x0 * x1 * x2;		
}
set<int> get_pr(int x) {
	set<int> res;
	for (int j = 2; j * j <= x; ++j) {
		while (x % j == 0) {
			res.insert(j);
			x /= j;
		}
	}
	if (x != 1) res.insert(x);
	return res;
}
set<int> get_pr(int x0, int x1, int x2) {
	set<int> a = get_pr(x0), b = get_pr(x1), c = get_pr(x2);
	for (int x : b) a.insert(x);
	for (int x : c) a.insert(x);
	return a;
}
int divisors[N * 10];
int get_div(int s1, int s2, int s3, int range) {
	set<int> pr = get_pr(s1, s2, s3);
	long long s = get_num(s1, s2, s3);
	int res = 0, sz = 1;
	divisors[0] = 1;
	for (int x : pr) {
		int cnt = 0;
		while (s % x == 0) {
			++cnt;
			s /= x;
		}
		int tsz = sz * (cnt + 1);
		for (int j = sz; j < tsz; ++j)
			divisors[j] = divisors[j - sz] * x;
		sz = tsz;
	}
	++range;
	for (int j = 0; j < sz; ++j) if (divisors[j] <= range) ++res;
	return res;
}
int a[N], b[N];
int gcd(int a, int b) {
	return min(a, b) == 0 ? max(a, b) : gcd(b, a % b);	
}

int solve(set<int> ns, int range, int s, int n) {
	int sz = 0;
	for (int x : ns) { 
		int cs = 0;
		int cn = 0;
		int ts = s;
		int tn = n;
		while (ts % x == 0) ts /= x, ++cs;
		while (tn % x == 0) tn /= x, ++cn;
		if (cn > cs) {
			a[sz] = x;
			for (int j = 0; j < cs; ++j) a[sz] *= x;
			++sz;
		}
	}
	int g = gcd(s, n);
	int res = 0;
	for (int mask = 0; mask < (1 << sz); ++mask) {
		int val = 1;
		for (int j = 0; j < sz; ++j) if (mask >> j & 1) val *= a[j];
		int cnt = range / val;
		if (__builtin_popcount(mask) & 1) {
			res -= cnt;
		} else {
			res += cnt;
		}
	}
	return res;
}
int32_t main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n1, n2, n3;
		int m1, m2, m3;
		int s1, s2, s3;
		cin >> n1 >> n2 >> n3;
		cin >> m1 >> m2 >> m3;
		cin >> s1 >> s2 >> s3;
		s1 *= 2;
		cout << solve(get_pr(n1, n2, n3), get_num(m1, m2, m3), get_num(s1, s2, s3), get_num(n1, n2, n3))
			+ get_div(s1, s2, s3, get_num(n1, n2, n3) - 1) << '\n';
	}
}