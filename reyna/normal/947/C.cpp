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

const int N = (int) 3e5 + 5, mod = (int) 0;
int nxt[N * 30][2], cnt[N * 30], sz, a[N], p[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) cin >> p[j];
	for (int j = 0; j < n; ++j) {
		int v = 0;
		for (int i = 29; i >= 0; --i) {
			int bit = p[j] >> i & 1;
			if (!nxt[v][bit]) {
				nxt[v][bit] = ++sz;
			}
			cnt[v]++;
			v = nxt[v][bit];
		}
		cnt[v]++;
	}
	for (int j = 0; j < n; ++j) {
		int v = 0, res = 0;
		for (int i = 29; i >= 0; --i) {
			int bit = a[j] >> i & 1;
			if (!nxt[v][bit] || !cnt[nxt[v][bit]]) {
				bit ^= 1;
			}
			res += bit << i;
			--cnt[v];
			v = nxt[v][bit];
		}
		--cnt[v];
		cout << (res ^ a[j]) << ' ';
		
	}
}