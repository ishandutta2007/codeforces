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
#define max(x, y) ((x) > (y) ? (x) : (y))
#define prev pre
const int N = (int) 1e5 + 6, mod = (int) 0;
int dp[N], f[N], head[N], prev[N][26], nxt[N][26], odp[N];
vector<int> good[N];
int main() {
	ios_base::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	for (int j = 2; j <= (int) t.size(); ++j) {
		int k = f[j - 1];
		while (k > 0 && t[j - 1] != t[k]) k = f[k];
		if (t[j - 1] == t[k]) ++k;
		f[j] = k;
	}
	for (int j = 0; j < (int) t.size() + 1; ++j) {
		int ch = (j == (int) t.size() ? -1 : t[j] - 'a');
		int v = j;
		for (int c = 0; c < 26; ++c) {
			if (c == ch) {
				nxt[v][c] = j + 1;
			} else {
				nxt[v][c] = nxt[f[v]][c];
			}
		}
		int flag = 0;
		int last = -1;
		for (int c = 0; c < 26; ++c) {
			if (nxt[v][c] != 0) {
				good[v].push_back(c);
			} else {
				if (!flag) good[v].push_back(c);
				flag = 1;
			}
		}
		head[v] = last;
		for (int x : good[v]) prev[v][x] = head[v], head[v] = x;
	}
//	cout << nxt[5][2] << endl;
	
	memset(dp, -63, sizeof dp);
	dp[0] = 0;
	int m = (int) t.size();
	for (int j = 0; j < (int) s.size(); ++j) {
		for (int st = 0; st < (int) t.size() + 1; ++st) odp[st] = dp[st], dp[st] = -1e9;
		int ch = (s[j] == '?' ? 26 : s[j] - 'a');
		for (int st = 0; st < (int) t.size() + 1; ++st) {
			if (ch == 26) {
				for (int c = head[st]; ~c; c = prev[st][c]) {
					if (c == ch || ch == 26) {
						dp[nxt[st][c]] = max(dp[nxt[st][c]], odp[st] + (st == m));
					}
				}
			} else {
				int c = ch;
				if (c == ch || ch == 26) {
					dp[nxt[st][c]] = max(dp[nxt[st][c]], odp[st] + (st == m));
				}
			}
		}
	}
	int res = 0;
	for (int j = 0; j < (int) t.size() + 1; ++j) {
		res = max(res, (j == (int) t.size()) + dp[j]);	
	}
	cout << res << endl;
}