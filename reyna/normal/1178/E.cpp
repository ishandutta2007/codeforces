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
int mark[N];
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	int l = 0, r = n - 1;
	while (l <= r) {
		if (s[l] == s[r]) {
			mark[l] = 1;
			mark[r] = 1;
			++l;
			--r;
		} else {
			if (s[l] == s[r - 1]) {
				--r;	
			} else if (s[l + 1] == s[r]) {
				++l;
			} else {
				++l;
				--r;
			}
		}
	}
	int cnt = 0;
	for (int j = 0; j < n; ++j)
		if (mark[j]) {
			++cnt;
		}
	if (n / 2 > cnt) {
		cout << "IMPOSSIBLE\n";
	} else {
		for (int j = 0; j < n; ++j)
			if (mark[j]) {
				cout << s[j];
			}
	}
}