//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
vi r;
vi dft(vi a, int l) {
	r.resize(l);
	for (int i = 1; i < l; i <<= 1)
		for (int j = 0; j < i; j++)
			r[i + j] = r[j] + l / i / 2;
	for (int i = 0; i < l; i++)
		if (r[i] > i)
			swap(a[i], a[r[i]]);
	for (int i = 1; i < l; i <<= 1) {
		int w = ksm(3, (mod - 1) / i / 2);
		for (int j = 0; j < l; j += (i << 1)) {
			int wn = 1;
			for (int k = 0; k < i; k++) {
				int fr = a[j + k];
				a[j + k] = (a[j + k] + 1ll * wn * a[i + j + k]) % mod;
				a[i + j + k] = (fr + 1ll * (mod - wn) * a[i + j + k]) % mod;
				wn = 1ll * w * wn % mod;
			}
		}
	}
	return a;
}
vi operator * (vi a, vi b) {
	int re = a.size() + b.size() - 1;
	int l = 1;
	while (l < re) l <<= 1;
	a.resize(l), b.resize(l);
	a = dft(a, l), b = dft(b, l);
	for (int i = 0; i < l; i++)
		a[i] = 1ll * a[i] * b[i] % mod;
	reverse(a.begin() + 1, a.end());
	a = dft(a, l);
	ll bk = ksm(l, mod - 2);
	for (int i = 0; i < l; i++)
		a[i] = 1ll * a[i] * bk % mod;
	a.resize(re);
	return a; 
} 

ll jc[maxn], bjc[maxn];

ll p[maxn], f[maxn];
ll c(int a, int b) {
    if (b > a || b < 0) return 0;
    return 1ll * jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
int main() {
    jc[0] = bjc[0] = 1;
    for (int i = 1; i < maxn; i++)
        jc[i] = jc[i - 1]   * i % mod, 
        bjc[i] = ksm(jc[i], mod - 2);
    int n;
    cin >> n;
    // p : fangan
    for (int i = 1; i <= n; i++) {
        p[i] = 0;
        if (i <= 2)
            for (int j = 0; j <= n - i; j++) {
                ll ch = c(n - i, j);
                ll cur = 1ll * ch * jc[j] % mod * jc[max(0, n - 2 - j)] % mod;
                if ((j + 1) * 2 <= n) cur = 0;
                p[i] = (p[i] + cur) % mod;
            }
        else {
            int md = ((n + 1) / 2) - 1;
            int lb = n - 2 - md;
            if (lb < i - 2) p[i] = 0;
            else {
                ll cur = c(lb + 1, i - 1);
                cur = cur * jc[i - 2] % mod;
                cur = cur * jc[n - i] % mod;
                p[i] = cur;
            }
        }
        if (i > 1) p[i] = p[i] * (i - 1) % mod;
        if (i == 1) p[i] = jc[n - 1];
        //cout << i << ' ' << p[i] << endl;
    }
    ll sum = 0;
    for (int i = n; i >= 1; i--) {
        f[i] = (p[i] - sum) % mod;
        sum = sum + p[i] * ksm(i - 1, mod - 2); sum %= mod;
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] < 0) f[i] += mod;
        printf("%lld ", f[i]);
    }
    return (0-0); //<3
}