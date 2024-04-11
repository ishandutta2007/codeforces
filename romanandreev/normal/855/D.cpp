#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}

const int maxn = (int)3e5 + 10;
const int MAXL = 18;

int p[maxn];
int t[maxn];
int up[maxn][MAXL + 1];
int h[maxn];
int sum[maxn];
int lca(int x, int y) {
  for (int i = MAXL; i >= 0; i--) {
    if (h[up[x][i]] >= h[y]) {
      x = up[x][i];
    }
  }
  for (int i = MAXL; i >= 0; i--) {
    if (h[up[y][i]] >= h[x]) {
      y = up[y][i];
    }
  }
  if (x == y) return x;
  for (int i = MAXL; i >= 0; i--) {
    if (up[x][i] != up[y][i]) {
      x = up[x][i];
      y = up[y][i];      
    }
  }
  assert(up[x][0] == up[y][0] && x != y);
  return up[x][0];
}
int go(int v, int x) {
  for (int i = MAXL; i >= 0; i--) if (x >= (1 << i)) {
    v = up[v][i];
    x -= (1 << i);
  }
  return v;
}
void solve() {
  int n;
  scanf("%d", &n);
  h[0] = 0;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &p[i], &t[i]);
    if (p[i] == -1) {
      p[i] = 0;
    }
    h[i] = h[p[i]] + 1;
    t[i]++;
    sum[i] = sum[p[i]] + (t[i] == 1);
  }
  up[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    up[i][0] = p[i];
  }
  for (int j = 1; j <= MAXL; j++) {
    for (int i = 0; i <= n; i++) {
      up[i][j] = up[up[i][j - 1]][j - 1];
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int tp, u, v;
    scanf("%d %d %d", &tp, &u, &v);
    int l = lca(u, v);
    if (tp == 1) {
      if (l == u && sum[v] == sum[u] + h[v] - h[u] && u != v) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      if (l != 0 && sum[u] == sum[l] + h[u] - h[l] && l != u && l != v && sum[v] - sum[l] == 0) {
        printf("YES\n");
      } else
      if (l == u && u != v && sum[v] - sum[l] == 0) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}