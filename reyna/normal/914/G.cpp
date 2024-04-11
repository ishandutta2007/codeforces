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

const int N = (int) 1 << 17, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b == 0 ? 1 : pw((LL) a * a % mod, b >> 1) * (LL) (b & 1 ? a : 1) % mod; }
void xorFFT(int a[N], bool inverse) {
	for (int len = 1; 2 * len <= N; len <<= 1) {
		for (int i = 0; i < N; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				int u = a[i + j];
				int v = a[i + len + j];
				a[i + j] = u + v;
				a[i + len + j] = u - v;
				if (a[i + j] >= mod) a[i + j] -= mod;
				if (a[i + len + j] < 0) a[i + len + j] += mod;
			}
		}
	}

	if (inverse) {
		for (int i = 0; i < N; i++)
			a[i] = a[i] * (LL) pw(N, mod - 2) % mod;
	}
}

void andFFT(int a[N], bool inverse) {
	for (int len = 1; 2 * len <= N; len <<= 1) {
		for (int i = 0; i < N; i += 2 * len) {
			for (int j = 0; j < len; j++) {
				int u = a[i + j];
				int v = a[i + len + j];

				if (!inverse) {
					a[i + j] = v;
					a[i + len + j] = u + v;
					if (a[i + len + j] >= mod) a[i + len + j] -= mod;
				} else {
					a[i + j] = -u + v;
					if (a[i + j] < 0) a[i + j] += mod;
					a[i + len + j] = u;
				}
			}
		}
	}
}
int partx[N], party[N], a[N], b[N], cur[N], f[N];
int main() {
	f[1] = 1;
	for (int j = 2; j < N; ++j) f[j] = (f[j - 1] + f[j - 2]) % mod;
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int mask = 0; mask < N; ++mask)
		for (int sub = mask; ; sub = (sub - 1) & mask) {
			int cmask = mask ^ sub;
			partx[mask] = (partx[mask] + (LL) a[cmask] * a[sub]) % mod;
			if (sub == 0) break;
		}
	memcpy(b, a, sizeof b);
	xorFFT(b, false);
	for (int j = 0; j < N; ++j) party[j] = (b[j] * (LL) b[j]) % mod;
	xorFFT(party, true);
	memcpy(cur, a, sizeof cur);
	for (int j = 0; j < N; ++j) {
		cur[j] = cur[j] * (LL) f[j] % mod;
		partx[j] = partx[j] * (LL) f[j] % mod;
		party[j] = party[j] * (LL) f[j] % mod;
	}
	andFFT(partx, false);
	andFFT(party, false);
	andFFT(cur, false);
	for (int j = 0; j < N; ++j) a[j] = (LL) partx[j] * party[j] % mod * cur[j] % mod;
	andFFT(a, true);
	int res = 0;
	for (int j = 0; j < 17; ++j) res = (res + a[1 << j]) % mod;
	cout << res << endl;
	
	
		
}