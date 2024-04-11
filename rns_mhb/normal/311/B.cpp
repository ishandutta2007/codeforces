#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 105

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

template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
typedef long long ll;
const ll inf = 1e18;
int n, m, p;
int d[N];
int h[N];
int t[N];
ll dp[M][N];
ll ans;

void solve(int g, int l, int r, int kl, int kr) {
    if (l > r) return;
    int m = l + r >> 1;
    dp[g][m] = inf;
    int k;
    for (int i = kl; i <= kr && i < m; i ++) {
        if (chkmin(dp[g][m], dp[g-1][i] + 1ll * t[m] * (m - i))) {
            k = i;
        }
    }
    solve(g, l, m - 1, kl, k);
    solve(g, m + 1, r, k, kr);
}

int main() {
    n = getint(), m = getint(), p = getint();
    for (int i = 2; i <= n; i ++) {
        d[i] = getint();
        d[i] += d[i-1];
    }
    for (int i = 1; i <= m; i ++) {
        h[i] = getint(), t[i] = getint();
        t[i] += d[n] - d[h[i]];
    }
    sort(t + 1, t + m + 1);
    for (int i = 1; i <= m; i ++) {
        dp[1][i] = 1ll * i * t[i];
    }
    for (int i = 2; i <= p; i ++) {
        solve(i, 1, m, 0, m);
    }
    ans = dp[p][m];
    for (int i = 1; i <= m; i ++) ans -= t[i];
    printf("%I64d\n", ans);
    return 0;
}