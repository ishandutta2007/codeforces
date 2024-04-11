#include <bits/stdc++.h>

using namespace std;

#define N 100100

vector <int> v[N];

typedef long long LL;

int n, f[N];
LL pl[N], mi[N];
LL val[N];

void dfs(int r, int pa = 0) {
  LL mp = 0, mm = 0;
  for(int i = 0; i < (int)v[r].size(); i ++) {
    int j = v[r][i];
    if(pa == j) continue;
    dfs(j, r);
    mp = max(pl[j], mp);
    mm = max(mi[j], mm);
  }
  val[r] += mp - mm;
  if(val[r] > 0) mm += val[r];
  else mp -= val[r];
  pl[r] = mp;
  mi[r] = mm;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i < n; i ++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i = 1; i <= n; i ++) scanf("%I64d", val + i);
  dfs(1);
  printf("%I64d\n", mi[1] + pl[1]);
  return 0;
}