#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define B 333
#define mod 1000000007

int n, q, t, a[B];
int d[B], vis[B];
vector <int> v[B];
int f[N];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d%d%d", &n, &q, &t);
  for(int i = 1; i <= n; i ++) scanf("%d", a + i);
  while(q --) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    d[y] ++;
  }
  for(int i = 1; i <= n; i ++) if(!d[i]) {
    vis[i] = 1;
    int j = i;
    while((int)v[j].size()) {
      int k = v[j][0];
      vis[k] = 1;
      t -= a[j];
      if(t < 0) { puts("0"); return 0; }
      a[k] += a[j];
      j = k;
    }
  }
  for(int i = 1 ;i <= n; i ++) if(!vis[i]) { puts("0"); return 0; }
  sort(a + 1, a + n + 1);
  f[0] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j + a[i] <= t; j ++) {
      f[j + a[i]] = (f[j] + f[j + a[i]]) % mod;
    }
  }
  printf("%d\n", f[t]);
  return 0;
}