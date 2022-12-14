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

const int N = (int) 1e5 + 5, mod = (int) 0;

int main() {
	int mask = (1 << 26) - 1;
	int n, res = 0;
	cin >> n;
	while (n--) {
		char c;
		cin >> c;
		if (c == '!') {
			if (__builtin_popcount(mask) == 1) ++res;
			string s;
			cin >> s;
			int contains = 0;
			for (auto c : s) contains |= 1 << (c - 'a');
			mask &= contains;
		} else if (c == '.') {	
			string s;
			cin >> s;
			int contains = 0;
			for (auto c : s) contains |= 1 << (c - 'a');
			mask ^= mask & contains;
		} else {
			char s;
			cin >> s;
			if (__builtin_popcount(mask) == 1) ++res;
			mask ^= mask & (1 << (s - 'a'));
		}
	}
	cout << max(0, res - 1) << endl;
}