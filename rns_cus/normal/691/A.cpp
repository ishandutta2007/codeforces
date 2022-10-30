#include <bits/stdc++.h>
using namespace std;
int n, x, ans;
int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x); if (!x) ans++;
  }
  if (n == 1) {
    if (ans) puts("NO");
    else puts("YES");
  }
  else {
    if (ans == 1) puts("YES");
    else puts("NO");
  }
}