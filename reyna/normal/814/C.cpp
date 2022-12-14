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

const int N = (int) 1505, mod = (int) 0;
int res[N][N];
vector<int> all[N];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int j = 0; j < n; ++j)
		all[s[j] - 'a'].push_back(j);
	for (int c = 0; c < 26; ++c) {
		all[c].push_back(n);
		for (int m = 0; m <= n; ++m) {
			int pt = 0, cur = 0;
			for (int st = 0; st < n; ++st) {
				if (pt < st) {
					pt = st;
					cur = 0;
				}
				while (true) {
					int tmp = pt;
					while (pt < n && s[pt] - 'a' == c) ++pt;	
					while (pt < n && cur < m && s[pt] - 'a' != c) ++pt, ++cur;
					if (tmp == pt) break;
				}
				res[c][m] = max(res[c][m], pt - st);
				cur -= (s[st] - 'a') != c;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int m;
		char c;
		cin >> m >> c;
		cout << res[c - 'a'][m] << '\n';
	}
}