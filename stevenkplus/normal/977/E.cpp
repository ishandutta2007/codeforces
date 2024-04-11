#include <cstdio>

const int MAXN = 200100;
int e1[MAXN];
int e2[MAXN];
int deg[MAXN];
int seen[MAXN];
int ans[MAXN];

int n, m;

bool test(int i, int par=0) {
  if (deg[i] != 2) return false;
  if (seen[i]) return ans[i];
  seen[i] = true;
  ans[i] = true;
  ans[i] = test(((e1[i] == par) ? e2[i] : e1[i]), i);
  return ans[i];
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    (e1[a] ? e2[a] : e1[a]) = b;
    (e1[b] ? e2[b] : e1[b]) = a;
    ++deg[a];
    ++deg[b];
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    if (!seen[i]) {
      if (test(i)) {
        ++ans;
      }
    }
  }
  printf("%d\n", ans);
}