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

const int N = (int) 5005, mod = (int) 0;
int nxt[N], ss[N][26];
int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	
	long double res = 0;
	for (int c = 0; c < 26; ++c) {
		memset(nxt, 0, sizeof nxt);
		memset(ss, 0, sizeof ss);
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (s[j] == c + 'a') {
				++cnt;
				for (int len = 1; len < n; ++len) {
					int pos = (j + len) % n;
					if (!ss[len][s[pos] - 'a'])
						nxt[len] |= 1 << (s[pos] - 'a');
					else
						nxt[len] &= ((1 << 26) - 1) - (1 << (s[pos] - 'a'));
					ss[len][s[pos] - 'a']++;
				}
			}
		}
		int mx = 0;
		for (int j = 1; j < n; ++j) mx = max(mx, __builtin_popcount(nxt[j]));
		res = res + (long double) mx / n;
	}
	cout << setprecision(30) << fixed << res << endl;
}