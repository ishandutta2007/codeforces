#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

char out[50][101];
char now[101];
int t, n, k;

void dfs(int i) {
  if (i == n) {
    rep(i, n) out[k][i] = now[i],
              out[k][n * 2 - i - 1] = now[i] ^ '(' ^ ')';
    out[k][n * 2] = 0;
    k++;
  } else {
    now[i] = '(', dfs(i + 1);
    if (k != n) now[i] = ')', dfs(i + 1);
  }
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    k = 0;
    dfs(0);
    rep(i, n) printf("%s\n", out[i]);
  }
}