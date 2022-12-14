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
#define int long long
typedef long long LL;

const int N = (int) 1e6 + 5, mod = (int) 1e9 + 7, base = 727;
int pw(int a, int b) { return b == 0 ? 1 : (LL) pw((LL) a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod; }
string s, t;
int p0[N], nxt[N], cnt0, cnt1, h[N];
int get_hash(int l, int r) {
	return (h[r] - h[l] * (LL) p0[r - l] % mod + mod) % mod;
}
int32_t main() {
	p0[0] = 1;
	for (int j = 1; j < N; ++j) p0[j] = p0[j - 1] * (LL) base % mod;
	cin >> s >> t;
	int n = (int) s.size(), m = (int) t.size();
	for (int j = 0; j <= n; ++j) nxt[j] = n;
	for (int j = n - 2; j >= 0; --j) {
		if (s[j] != s[j + 1]) {
			nxt[j] = j + 1;
		} else {
			nxt[j] = nxt[j + 1];
		}
	}
	int res = 0;
	for (int j = 0; j < m; ++j) h[j + 1] = (h[j] * base + t[j]) % mod;
	for (auto c : s) cnt0 += (c == '0'), cnt1 += (c == '1');
	for (int s0 = 1; s0 <= m; ++s0) {
		int okay = 1;
		int rem = m - (s0 * cnt0);
		if (rem <= 0) continue;
		if (rem % cnt1 != 0) continue;
		int s1 = rem / cnt1;
		int h0 = -1, h1 = -1, pos = 0;
		for (int j = 0; j < n; ++j) {
			if (s[j] == '0') {
				if (h0 != -1 && get_hash(pos, pos + s0) != h0)
					okay = 0;
				h0 = get_hash(pos, pos + s0);
				pos += s0;
			} else {
				if (h1 != -1 && get_hash(pos, pos + s1) != h1)
					okay = 0;
				h1 = get_hash(pos, pos + s1);
				pos += s1;
			}
		}
		if (h0 == h1) okay = 0;
		res += okay;
	}
	cout << res << endl;
	
}