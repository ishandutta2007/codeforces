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

const int N = (int) 55, mod = (int) 0;
string shift(string s, int val) {
	string t = s;
	for (int j = 0; j < (int) s.size(); ++j)
		t[j] = s[(j + val) % (int) s.size()];
	return t;
}
string s[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j)
		cin >> s[j];
	int res = 1e9;
	for (int shift0 = 0; shift0 < (int) s[0].size(); ++shift0) {
		int cur_res = shift0;
		for (int j = 0; j < n; ++j) {
			int flag = 0;
			for (int move = 0; move < (int) s[0].size(); ++move) {
				if (shift(s[j], move) == s[0]) {
					cur_res += move;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				cout << -1 << endl;
				return 0;
			}
		}
		s[0] = shift(s[0], 1);
		res = min(cur_res, res);
	}
	cout << res << endl;
}