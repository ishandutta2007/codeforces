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

const int N = (int) 2e5 + 5, base = 727, sq = 340, mod = (int) (1 << 23) * 17 * 7 + 1;
int nxt[N][26], ind[N], sz = 1, h[N], pw[N], qk[N], hashed[N];
vector<int> appear[N];
string t[N];
string s;
int main() {
	memset(ind, -1, sizeof ind);
	cin >> s;
	int n = (int) s.size();
	pw[0] = 1;
	for (int i = 0; i < n; ++i)
		h[i + 1] = (h[i] * (LL) base + s[i]) % mod, pw[i + 1] = (LL) pw[i] * base % mod;
	int m;
	cin >> m;
	vector<int> all;
	for (int j = 0; j < m; ++j) {
		cin >> qk[j] >> t[j];	
		if ((int) t[j].size() >= sq) {
			int id = (int) all.size();
			for (auto c : t[j]) hashed[id] = ((LL) hashed[id] * base + c) % mod;
			all.pb(j);
		} else {
			int v = 0;
			for (auto c : t[j]) {
				if (!nxt[v][c - 'a']) {
					nxt[v][c - 'a'] = sz++;
				}
				v = nxt[v][c - 'a'];
			}
			ind[v] = j;
		}
		
	}
	for (int pos = 0; pos < n; ++pos) {
		int v = 0;
		for (int r = pos + 1; r <= min(n, sq + pos + 1); ++r) {
			if (!nxt[v][s[r - 1] - 'a']) {
				break;
			}
			v = nxt[v][s[r - 1] - 'a'];
			if (ind[v] >= 0) {
				appear[ind[v]].pb(pos);	
			}
		}
		int id = 0;
		for (int x : all) {
			int r = pos + (int) t[x].size();
			int hs = (h[r] - (LL) h[pos] * pw[r - pos] % mod + mod) % mod;
			if (hs == hashed[id]) {
				appear[x].pb(pos);
			}
			++id;
		}
	}
	for (int j = 0; j < m; ++j) {
		if (appear[j].size() < qk[j]) {
			cout << -1 << '\n';	
		} else {
			int res = n;
			for (int i = 0; i + qk[j] - 1 < (int) appear[j].size(); ++i) {
				res = min(res, (appear[j][i + qk[j] - 1] - appear[j][i]	+ (int) t[j].size()));
			}
			cout << res << '\n';
		}
	}
	
}