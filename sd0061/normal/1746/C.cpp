#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

void work() {
  int n, k;
  scanf("%d" , &n);
  std::vector<int> a(n), p(n + 1);
  for (int i = 0 ; i < n ; ++ i) {
    scanf("%d" , &a[i]);
    p[a[i]] = i;
  }
  std::vector<int> res(n);
  for (int i = 1 ; i <= n ; ++ i) {
    int x = p[n + 1 - i];
    res[i - 1] = x  + 1;
  }
  for (int _i = 0 ; _i < res.size() ; ++ _i) {
    printf("%d%c" , res[_i], " \n"[_i + 1 == res.size()]);
  }



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