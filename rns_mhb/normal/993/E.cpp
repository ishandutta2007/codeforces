#include <bits/stdc++.h>

using namespace std;



#define N 534290



typedef long long ll;

typedef long double ldb;

typedef double db;

int n, x;

int a[N];

ll f[N], g[N];



namespace fft{ /// multiply two polynomial nlog(n) time modulo p

	const int L = 19, FN = (1<<L);

	int rev[FN];

	const db pi = 3.1415926535897932384626433832795028841971l;

	const db two_pi = pi * 2;

	struct cp{

		db x, y;

		cp() {}

		cp(db _x) : x(_x), y(0) {}

		cp(db _x, db _y) : x(_x), y(_y) {}

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



	void multiply(int *a, int *b, int *c, int n, int mod) {

		for (int i = 0; i < n; i ++) {

			f[i] = cp( (db)(a[i]>>15), (db)(a[i]&32767) );

			g[i] = cp( (db)(b[i]>>15), (db)(b[i]&32767) );

		}

		dft(f, n, 0);

		dft(g, n, 0);

		for (int i = 0; i < n; i ++) {

			int j = i ? n - i : 0;

			h[i] = ((f[i]+!f[j])*(!g[j]-g[i]) + (!f[j]-f[i])*(g[i]+!g[j])) * cp(0, 0.25);

		}

		dft(h, n, 1);

		for (int i = 0; i < n; i ++) c[i] = ((ll(h[i].x + 0.5) % mod)<<15) % mod;

		for (int i = 0; i < n; i ++) {

			int j = i ? n - i : 0;

			h[i] = (!f[j]-f[i])*(!g[j]-g[i])*cp(-0.25, 0) + (f[i]+!f[j])*(g[i]+!g[j])*cp(0, 0.25);

		}

		dft(h, n, 1);

		for (int i = 0; i < n; i ++) {

			c[i] = (c[i] + ll(h[i].x + 0.5) + ((ll(h[i].y + 0.5) % mod)<<30)) % mod;

		}

	}



	void multiply_simple(ll *a, ll *b, ll *c, int n) {

		for (int i = 0; i < n; i ++) {

			f[i] = cp((db)a[i]);

			g[i] = cp((db)b[i]);

		}

		dft(f, n, 0);

		dft(g, n, 0);

		for (int i = 0; i < n; i ++) {

			h[i] = f[i] * g[i];

		}

		dft(h, n, 1);

		for (int i = 0; i < n; i ++) c[i] = ll(h[i].x + 0.5);

	}

}



ll ans[N];



inline char nc(){

  static char buf[100000],*p1=buf,*p2=buf;

  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }

  return *p1++;

}



inline int getint(){

  int x;

  char c=nc(),b=1;

  if(c == -1)

    return 0;

  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;

  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;

  return x;

}



int main() {

    fft::init();

    n = getint(), x = getint();

    f[0] ++;

    for (int i = 1; i <= n; i ++) {

        a[i] = getint();

        a[i] = (a[i] < x);

        a[i] += a[i-1];

        f[a[i]] ++;

    }

    int nn = 0;

    while (f[nn]) nn ++;

    int sz = 1;

    while (2 * n +2> sz) sz <<= 1;

    for (int i = nn; i < sz; i ++) f[i] = 0;

    for (int i = 0; i < sz; i ++) g[i] = f[sz-1-i];

    ans[0] = 0;

    for (int i = 0; i < nn; i ++) {

        ans[0] += 1ll * f[i] * (f[i] - 1) / 2;

    }

    fft::multiply_simple(f, g, f, sz);

    for (int k = 1; k <= n; k ++) ans[k] = f[sz-1-k];

    for (int i = 0; i <= n; i ++) {

        printf("%I64d ", ans[i]);

    }

    return 0;

}