#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int P = 998244353, lim = 50;
int n, x, y, f[55][25][25][55], ans[55];
// length, inv, i>i+1, lstrnk 

void inc(int &x, int y) { x = (x + y) % P; }

void init() {
	f[1][0][0][1] = 1;
	for(int i = 1; i <= lim; i++)
		for(int j = 0; j <= 11; j++)
			for(int k = 0; k <= 11; k++) 
				for(int l = 1; l <= i; l++) {
					for(int r = 1; r <= i + 1; r++)
						if(j + i + 1 - r <= 11) inc(f[i + 1][j + i + 1 - r][k + (r <= l)][r], f[i][j][k][l]);
				}
}

namespace BM {
	const int N = 55, P = 998244353;
	int n, m, a[N], f[N][N], sze[N], cnt, fail[N], delta[N];
	int res[N], base[N], g[N];
	
	void clear() {
		memset(a, 0, sizeof(a)), memset(f, 0, sizeof(f)), memset(sze, 0, sizeof(sze));
		memset(fail, 0, sizeof(fail)), memset(delta, 0, sizeof(delta));
		memset(res, 0, sizeof(res)), memset(base, 0, sizeof(base)), memset(g, 0, sizeof(g));
		n = m = cnt = 0;
	}
	
	int qpow(int x, int y) {
	    int res = 1;
	    while(y) res = 1ll * res * ((y & 1)? x : 1) % P, x = 1ll * x * x % P, y >>= 1;
	    return res;
	}
	
	void Berlekamp_Massey() {
	    for(int i = 1; i <= n; i++) {
	        int now = a[i];
	        for(int j = 1; j <= sze[cnt]; j++) now = (now - 1ll * f[cnt][j] * a[i - j] % P) % P;
	        delta[i] = now;
	        if(!now) continue;
	        fail[cnt] = i;
	        if(!cnt) { sze[++cnt] = i; continue; }
	        int w = 0, mn = 0x3f3f3f3f;
	        for(int j = 0; j < cnt; j++) 
	            if(sze[j] + 1 + i - fail[j] - 1 < mn) mn = sze[j] + 1 + i - fail[j] - 1, w = j;
	        int mul = 1ll * delta[i] * qpow(delta[fail[w]], P - 2) % P;
	        ++cnt;
	        sze[cnt] = max(sze[cnt - 1], mn);
	        for(int j = 1; j <= i - fail[w] - 1; j++) f[cnt][j] = 0;
	        f[cnt][i - fail[w]] = mul;
	        for(int j = 1; j <= sze[w]; j++) f[cnt][i - fail[w] + j] = -1ll * f[w][j] * mul % P;
	        for(int j = 1; j <= sze[cnt - 1]; j++) f[cnt][j] = (f[cnt][j] + f[cnt - 1][j]) % P;
	    }
	}
	
	void mul(int *f, int *g, int *p, int n1, int n2, int n3) {
	    static int tmp[N], len;
	    len = n1 + n2;
	    for(int i = 0; i <= len; i++) tmp[i] = 0;
	    for(int i = 0; i <= n1; i++)
	        for(int j = 0; j <= n2; j++)
	            tmp[i + j] = (tmp[i + j] + 1ll * f[i] * g[j] % P) % P;
	    for(int i = len; i >= n3; i--) {
	        int now = tmp[i];
	        if(!now) continue;
	        for(int j = n3; j >= 0; j--) 
	            tmp[i + j - n3] = (tmp[i + j - n3] - 1ll * now * p[j] % P) % P/*, printf("%d\n", i + j - n3)*/;
	    }
	    for(int i = 0; i < n3; i++) f[i] = tmp[i];
	}
	
	int solve(int *f, int k, int n) {
	    for(int i = 1; i <= k / 2; i++) swap(f[i], f[k - i + 1]);
	    for(int i = 0; i < k; i++) f[i] = -f[i + 1]; f[k] = 1;
	    res[0] = 1, base[1] = 1;
	    while(n) {
	        if(n & 1) mul(res, base, f, k, k, k);
	        mul(base, base, f, k, k, k), n >>= 1;
	    }
	    int ans = 0;
	    for(int i = 0; i < k; i++) ans = (ans + 1ll * res[i] * a[i + 1] % P) % P;
	    return (ans + P) % P;
	}
	
	int main() {
	    Berlekamp_Massey();
//	    cout << sze[cnt] << endl;
	    return solve(f[cnt], sze[cnt], m);;
	}
}

void solve() {
	int n = get(), k = get(), x = get();
	BM::clear();
	BM::n = 51, BM::m = n;
	for(int i = 0; i <= 50; i++)
		for(int j = 1; j <= i; j++)
			inc(BM::a[i + 1], f[i][k][x][j]);
	int ans = BM::main();
	cout << ans << endl;
}

void file() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
}

main() {
//	file();
	init();
	int T = get();
	while(T--) solve();
	return 0;
}