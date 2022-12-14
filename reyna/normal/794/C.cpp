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

const int N = (int) 1e6 + 6, mod = (int) 0;
int sl, sr, tl, tr, pl, pr;
char p[N];
int main() {
	string s, t;
	cin >> s >> t;
	sort(ALL(s));
	sort(ALL(t));
	int n = SZ(s);
	sl = tl = pl = 0;
	sr = tr = pr = n - 1;
	tl = n - (n / 2);
	sr = (n / 2) + (n % 2) - 1;
	for (int j = 0; j < n; ++j) {
		if (j % 2 == 0) {
			if (s[sl] < t[tr]) {
				p[pl++] = s[sl++];	
			} else {
				p[pr--] = s[sr--];
			}
		} else {
			if (t[tr] > s[sl]) {
				p[pl++] = t[tr--];
			} else {
				p[pr--] = t[tl++];
			}
		}
	}
	for (int j = 0; j < n; ++j)
		cout << p[j];
}