#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  --m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  if (!a[0]) {
    puts("NO");
  } else if (a[m]) {
    puts("YES");
  } else if (!b[m]) {
    puts("NO");
  } else {
    for (int i = m + 1; i < n; ++i) {
      if (a[i] && b[i]) {
        puts("YES");
        return 0;
      }
    }
    puts("NO");
  }
  return 0;
}