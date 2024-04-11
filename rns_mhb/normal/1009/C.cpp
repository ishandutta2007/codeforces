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

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 100005



int n, m, x, d;

int a[N];

ll tot;



int main() {

    scanf("%d %d", &n, &m);

    while (m --) {

        scanf("%d %d", &x, &d);

        tot += 1ll * x * n;

        if (d > 0) {

            tot += 1ll * d * n * (n - 1) / 2;

        }

        else {

            int nn = n / 2;

            if (n & 1) {

                tot += 1ll * d * nn * (nn + 1);

            }

            else {

                tot += 1ll * d * nn * nn;

            }

        }

    }

    printf("%.12lf\n", 1.0 * tot / n);

    return 0;

}