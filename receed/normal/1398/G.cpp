#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1<<20;

ll pw(ll x, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1)
            r = r * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return r;
}
 
void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = pw(n, mod - 2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

const int N = 1 << 18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x, y, q, cl;
    cin >> n >> x >> y;
    vector<int> a(N * 2), b(N * 2), c(N * 2);
    rep(i, n + 1) {
        cin >> q;
        a[q] = 1;
        b[N - q] = 1;
    }
    fft(a, 0);
    fft(b, 0);
    rep(i, 2 * N)
        c[i] = (ll) a[i] * b[i] % mod;
    fft(c, 1);
    cin >> q;
    rep(i, q) {
        cin >> cl;
        cl /= 2;
        ll ans = 0;
        for (ll j = 1; j * j <= cl; j++)
            if (cl % j == 0) {
                if (j > y && j - y <= x && c[N + j - y])
                    ans = max(ans, j);
                if (cl / j > y && cl / j - y <= x && c[N + cl / j - y])
                    ans = max(ans, cl / j);
            }
        if (ans == 0)
            ans = -1;
        else
            ans *= 2;
        cout << ans << ' ';
    }
}