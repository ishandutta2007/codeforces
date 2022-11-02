#include <bits/stdc++.h>

using namespace std;



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



#define N 1000005



int n, ans;

int a[N], c[N];



int main() {

    scanf("%d", &n);

    c[1] = 1;

    for (int i = 2, j = 1; i <= n; i ++, j = 2ll * j % mod) {

        c[i] = 1ll * (i + 1) * j % mod;

    }

    reverse(c + 1, c + n + 1);

    for (int i = 1; i <= n; i ++) {

        scanf("%d", &a[i]);

        (ans += 1ll * c[i] * a[i] % mod) %= mod;

    }

    printf("%d\n", ans);

    return 0;

}