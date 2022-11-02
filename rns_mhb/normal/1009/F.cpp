#include <bits/stdc++.h>

using namespace std;



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



#define N 1000005



int n, timp;

vector<int> v[N];

int dt[N], ft[N], ver[N], sz[N], hs[N], dep[N], ans[N];



void dfs(int x, int par = 0) {

    dt[x] = ++timp;

    ver[timp] = x;

    hs[x] = -1;

    sz[x] = 1;

    dep[x] = dep[par] + 1;

    int mx = 0;

    for (int i = 0; i < v[x].size(); i ++) {

        int y = v[x][i];

        if (y == par) continue;

        dfs(y, x);

        sz[x] += sz[y];

        if (chkmax(mx, sz[y])) hs[x] = y;

    }

    ft[x] = timp;

}



map<int, int> mp;

int ps, mx;



void push_bag(int x) {

    mp[dep[x]] ++;

    int cnt = mp[dep[x]];

    if (mx < cnt)  ps = dep[x], mx = cnt;

    else if (mx == cnt && dep[x] < ps) ps = dep[x];

}



void dsu(int x, int par = 0, int keep = 1) {

    for (int i = 0; i < v[x].size(); i ++) {

        int y = v[x][i];

        if (y == par || y == hs[x]) continue;

        dsu(y, x, 0);

    }

    if (hs[x] != -1) dsu(hs[x], x, 1);

    push_bag(x);

    for (int i = 0; i < v[x].size(); i ++) {

        int y = v[x][i];

        if (y == par || y == hs[x]) continue;

        for (int j = dt[y]; j <= ft[y]; j ++) {

            push_bag(ver[j]);

        }

    }

    ans[x] = ps - dep[x];

    if (keep) return;

    mp.clear();

    mx = 0;

}



int main() {

    n = getint();

    memset(hs, -1, sizeof hs);

    for (int i = 1; i < n; i ++) {

        int x, y;

        x = getint(), y = getint();

        v[x].pb(y), v[y].pb(x);

    }

    dfs(1);

    dsu(1);

    for (int i = 1; i <= n; i ++) {

        putint(ans[i]), pc('\n');

    }

    return 0;

}