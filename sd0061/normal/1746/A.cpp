#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

void work() {
  int n, k;
  scanf("%d%d" , &n, &k);
  std::vector<int> a(n);
  int x = 0 , y = 0;
  for (int i = 0 ; i < n ; ++ i) {
    scanf("%d" , &a[i]);
    x += (a[i] == 0);
    y += (a[i] == 1);
  }
  // printf("%d %d\n", x ,y);
  puts(y && x + y >= k ? "YES" : "NO");

}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}