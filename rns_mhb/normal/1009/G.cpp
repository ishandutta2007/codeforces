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

#define K 6

#define M 70



int n, m, ps;

int ans;

char s[N];

int a[M], b[M], cnt[M], msk[N];



bool good() {

    memcpy(b, a, sizeof b);

    for (int i = 0; i < K; i ++)

    for (int j = 0; j < (1 << K); j ++) {

        if (j & (1 << i)) {

            b[j] += b[j^(1<<i)];

        }

    }

    for (int mask = 0; mask < (1 << K); mask ++) {

        int tmp = 0;

        for (int i = 0; i < K; i ++) if (mask & (1 << i)) tmp += cnt[i];

        if (b[mask] > tmp) return 0;

    }

    return 1;

}



int main() {

    gets(s);

    n = strlen(s);

    for (int i = 0; i < n; i ++) cnt[s[i]-'a'] ++;

    for (int i = 0; i < n; i ++) msk[i] = (1 << K) - 1;

    scanf("%d", &m);

    while (m --) {

        scanf("%d %s", &ps, s); ps --;

        msk[ps] = 0;

        for (int i = 0; s[i]; i ++) msk[ps] |= (1 << s[i] - 'a');

    }

    for (int i = 0; i < n; i ++) a[msk[i]] ++;

    for (int i = 0; i < n; i ++) {

        a[msk[i]] --;

        ans = -1;

        for (int j = 0; j < K; j ++) {

            cnt[j] --;

            if (((msk[i] >> j) & 1) && good()) {

                ans = j;

                break;

            }

            cnt[j] ++;

        }

        if (ans == -1) return puts("Impossible"), 0;

        putchar(ans + 'a');

    }

    putchar('\n');

    return 0;

}