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



#define N 100005

#define K 105



int n, m, k, s;

int clr[N];

int dist[K][N];

vector<int> v[N], w[N];

int tmp[N], cnt;

queue<int> q;



int main() {

    n = getint(), m = getint(), k = getint(), s = getint();

    for (int i = 1; i <= n; i ++) {

        clr[i] = getint();

        w[clr[i]].pb(i);

    }

    while (m --) {

        int x, y;

        x = getint(), y = getint();

        v[x].pb(y), v[y].pb(x);

    }

    int rt = n + 1;

    for (int i = 1; i <= k; i ++) {

        for (int j = 1; j <= n; j ++) dist[i][j] = inf;

        while (!q.empty()) q.pop();

        for (int j = 0; j < w[i].size(); j ++) {

            int x = w[i][j];

            dist[i][x] = 0;

            q.push(x);

        }

        while (!q.empty()) {

            int x = q.front(); q.pop();

            for (int j = 0; j < v[x].size(); j ++) {

                int y = v[x][j];

                if (dist[i][y] > dist[i][x] + 1) {

                    dist[i][y] = dist[i][x] + 1;

                    q.push(y);

                }

            }

        }

    }



    for (int i = 1; i <= n; i ++) {

        for (int j = 1; j <= k; j ++) tmp[j] = dist[j][i];

        sort(tmp + 1, tmp + k + 1);

        ll ans = 0;

        for (int j = 1; j <= s; j ++) ans += tmp[j];

        printf("%I64d ", ans);

    }

    return 0;

}