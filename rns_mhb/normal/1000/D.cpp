#include <bits/stdc++.h>

using namespace std;



#define gc getchar

#define pc putchar



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



inline void putint(int x) {

  static int a[11], i; i = 0;

  if (x < 0) pc('-'), x = -x;

  do { a[i ++] = x % 10 ^ 48; x /= 10; } while (x);

  while (i) pc(a[--i]);

}



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 998244353;

const double eps = 1e-7;



#define N 1005



int fc[N], rfc[N], ri[N];

void calc_factorial() {

    fc[0] = fc[1] = rfc[0] = rfc[1] = ri[1] = 1;

    for (int i = 2; i < N; i ++) {

        int q = mod / i, r = mod % i;

        ri[i] = 1ll * (mod - q) * ri[r] % mod;

        fc[i] = 1ll * fc[i-1] * i % mod;

        rfc[i] = 1ll * rfc[i-1] * ri[i] % mod;

    }

}



int C(int n, int k) {

	if (k < 0 || k > n) return 0;

	if (k == 0 || k == n) return 1;

	return 1ll * (1ll * fc[n] * rfc[k] % mod) * rfc[n-k] % mod;

}



int n;

int a[N], f[N], g[N];



int main() {

    calc_factorial();

    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

    for (int i = n; i; i --) {

        f[i] = 0;

        for (int j = i + 1; j <= n; j ++) {

            int tmp = C(j - i - 1, a[i] - 1);

            tmp = 1ll * tmp * (1 + g[j+1]) % mod;

            (f[i] += tmp) %= mod;

        }

        g[i] = (g[i+1] + f[i]) % mod;

    }

    printf("%d\n", g[1]);

    return 0;

}