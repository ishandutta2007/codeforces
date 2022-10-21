#include<bits/stdc++.h>
using namespace std;

#define N 125100
#define M 1 << 15

char s[N << 1], t[N << 1];

bool con[10][10], vis[10];
int num[10][10], cnt[M];

void dfs(int u) {
    vis[u] = 1;
    for(int v = 0; v < 6; v ++) if(!vis[v] && con[u][v]) dfs(v);
}

void prepare() {
    for(int i = 0, k = 0; i < 6; i ++) for(int j = i + 1; j < 6; j ++) num[i][j] = num[j][i] = k ++;
    for(int key = 0; key < (1 << 15); key ++) {
        for(int i = 0, k = 0; i < 6; i ++) for(int j = i + 1; j < 6; j ++, k ++) con[j][i] = con[i][j] = key >> k & 1;
        int &x = cnt[key] = 6;
        for(int i = 0; i < 6; i ++) vis[i] = 0;
        for(int i = 0; i < 6; i ++) if(!vis[i]) dfs(i), x --;
    }
}

int n, m;
int a[N << 2], b[N << 2], c[N << 2];

const int mod = 1e9 + 7;

int pow(int a, int b) {
    int ans = 1;
    for( ; b; b >>= 1) {
        if(b & 1) ans = 1ll * a * ans % mod;
        a = 1ll * a * a % mod;
    }
    return ans;
}

int inverse(int a, int p = mod) {
    return pow(a, p - 2);
}

namespace fft{
    typedef long long ll;
	const int L = 18;
	const int FN = 1 << L;
	int rev[FN];
	const double pi = 3.1415926535897932384626433832795028841971l;
	const double two_pi = pi * 2;
	struct cp{
		double x, y;
		cp() {}
		cp(double _x) : x(_x), y(0) {}
		cp(double _x, double _y) : x(_x), y(_y) {}
		inline cp operator + (const cp &p) const { return cp(x+p.x, y+p.y); }
		inline cp operator - (const cp &p) const { return cp(x-p.x, y-p.y); }
		inline cp operator * (const cp &p) const { return cp(x*p.x-y*p.y, x*p.y+y*p.x); }
		inline cp operator !() const { return cp(x, -y); }
	} nw[FN+1], f[FN], g[FN], h[FN];
	void init() {
		rev[0] = 0; for (int i = 1; i < FN; i ++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(L-1));
		nw[0] = nw[FN] = cp(1,0);
		for (int i = 1; i <= (FN>>1); i ++) nw[i] = cp(cos(i*two_pi/FN), sin(i*two_pi/FN));
		for (int i = (FN>>1)+1; i < FN; i ++) nw[i] = !nw[FN-i];
	}
	void dft(cp *a, int n, int fg) {
		int d = __builtin_ctz(FN / n);
		for (int i = 0; i < n; i ++) if (i < (rev[i]>>d)) swap(a[i], a[rev[i]>>d]);
		for (int size = 2; size <= n; size <<= 1) {
			int step = FN / size; if (fg) step = -step;
			for (int i = 0; i < n; i += size) {
				cp *u = a + i, *v = a + (i+(size>>1)), *w = fg ? nw + FN : nw;
				for (int k = (size>>1); k --; ) {
					cp tmp = (*v) * (*w);
					*v = *u - tmp, *u = *u + tmp;
					u ++, v ++, w += step;
				}
			}
		}
		if (fg) for (int i = 0; i < n; i ++) a[i].x /= n, a[i].y /= n;
	}
	void multiply(int *a, int *b, int *c, int n) {
		for(int i = 0; i < n; i ++) {
			f[i] = cp((double)(a[i]>>15), (double)(a[i]&32767));
			g[i] = cp((double)(b[i]>>15), (double)(b[i]&32767));
		}
		dft(f, n, 0);
		dft(g, n, 0);
		for(int i = 0; i < n; i ++) {
			int j = i ? n - i : 0;
			h[i] = ((f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j])) * cp(0, 0.25);
		}
		dft(h, n, 1);
		for(int i = 0; i < n; i ++) c[i] = (((int)(h[i].x + 0.5) % mod)<<15);
		for(int i = 0; i < n; i ++) {
			int j = i ? n - i : 0;
			h[i] = (!f[j]-f[i])*(!g[j]-g[i])*cp(-0.25, 0) + (f[i]+!f[j])*(g[i]+!g[j])*cp(0, 0.25);
		}
		dft(h, n, 1);
		for(int i = 0; i < n; i ++) c[i] = (c[i] + (int)(h[i].x + 0.5) + (((int)(h[i].y + 0.5))<<30));
	}
	void square(int *a, int *c, int n) {
		for (int i = 0; i < n; i ++) f[i] = cp( (double)(a[i]>>15), (double)(a[i]&32767) );
		dft(f, n, 0);
		for(int i = 0; i < n; i ++) {
			int j = i ? n - i : 0;
			h[i] = ((f[i]+!f[j])*(!f[j]-f[i])) * cp(0, 0.5);
		}
		dft(h, n, 1);
		for(int i = 0; i < n; i ++) c[i] = (((int)(h[i].x + 0.5))<<15);
		for(int i = 0; i < n; i ++) {
			int j = i ? n - i : 0;
			h[i] = (!f[j]-f[i])*(!f[j]-f[i])*cp(-0.25, 0) + (f[i]+!f[j])*(f[i]+!f[j])*cp(0, 0.25);
		}
		dft(h, n, 1);
		for(int i = 0; i < n; i ++) c[i] = (c[i] + (int)(h[i].x + 0.5) + (((int)(h[i].y + 0.5))<<30));
	}
	void multiply_simple(int *a, int *b, int *c, int n) {
		for (int i = 0; i < n; i ++) {
			f[i] = cp((double)a[i]);
			g[i] = cp((double)b[i]);
		}
		dft(f, n, 0);
		dft(g, n, 0);
		for (int i = 0; i < n; i ++) {
			h[i] = f[i] * g[i];
		}
		dft(h, n, 1);
		for (int i = 0; i < n; i ++) c[i] = int(h[i].x + 0.5);
	}
}
using fft::FN;
using fft::multiply;
using fft::square;

void solve() {
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    reverse(t, t + m);
    int bin = 1;
    while(bin < n) bin <<= 1;
    for(int i = n; i < bin; i ++) s[i] = 0;
    for(int j = m; j < bin; j ++) t[j] = 0;
    for(int i = 0; i < 6; i ++) for(int j = 0; j < 6; j ++) if(i != j) {
        for(int k = 0; k < bin; k ++) a[k] = s[k] == 'a' + i, b[k] = t[k] == 'a' + j;
        multiply(a, b, a, bin);
        for(int k = m - 1; k < n; k ++) if(a[k]) c[k] |= 1 << num[i][j];
    }
    for(int i = m - 1; i < n; i ++) printf("%d\n", cnt[c[i]]);
}

int main() {
    fft::init();
    prepare();
    solve();
}