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
	int cnta = 0;
	string s;
	cin >> s;
	string t = "";
	for (auto c : s) cnta += (c == 'a');
	int n = (int) s.size();
	if ((n - cnta) & 1) {
		cout << ":(" << endl;
		return 0;
	}
	int len = cnta + (n - cnta) / 2;
	for (int j = 0; j < len; ++j)
		cnta -= (s[j] == 'a');
	if (cnta) {
		cout << ":(" << endl;
		return 0;
	}
	string p = "";
	for (int j = 0; j < len; ++j)
		if (s[j] != 'a')
			t += s[j];
	for (int j = len; j < n; ++j)
		p += s[j];
	if (p != t) {
		cout << ":(" << endl;
		return 0;
	}
	t = "";
	for (int j = 0; j < len; ++j)
		t += s[j];
	cout << t << endl;
}