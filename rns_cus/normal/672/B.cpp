#include <bits/stdc++.h>
using namespace std;
char s[100010];
int vis[256], n, dif;

int main() {

  scanf("%d", &n);
  scanf("%s", s);
  if (n > 26) {
   return puts("-1"), 0;
  }
  for (int i = 0; i < n; i++) {
    if (!vis[s[i]]) dif++; vis[s[i]] = 1;
  }
  printf("%d\n", n - dif);
}