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

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 1005



int n, a, b;

bool fg;



int main() {

    scanf("%d %d %d", &n, &a, &b);

    if (a > 1 && b > 1) return puts("NO"), 0;

    if (a == 1 && b == 1) {

        if (n == 2 || n == 3) return puts("NO"), 0;

    }

    puts("YES");

    if (a == 1) fg = 1, swap(a, b);

    for (int i = 1; i <= n; i ++) {

        for (int j = 1; j <= n; j ++) {

            bool ans;

            if (i == j) ans = 0;

            else {

                if (i >= a && j >= a && abs(i - j) == 1) ans = 1;

                else ans = 0;

                ans ^= fg;

            }

            pc(ans + '0');

        }

        pc('\n');

    }

    return 0;

}