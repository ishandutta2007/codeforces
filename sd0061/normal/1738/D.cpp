#include <bits/stdc++.h>
using int64 = long long;
const int N = 100005;

int n, a[N];
void work() {
  scanf("%d", &n);
  int L = 0, R = n;
  for (int i = 1 ; i <= n ; ++ i) {
    scanf("%d" , &a[i]);
    if (i < a[i]) {
      L = std::max(L , i);
    } else if (i > a[i]) {
      R = std::min(R, i - 1);
    }
  }
  printf("%d\n", L);
  assert(L == R);
  std::map<int, std::vector<int>> h;
  std::set<int> t;
  for (int i = 1 ; i <= n ; ++ i) {
    t.insert(a[i]);
    h[a[i]].emplace_back(i);
  }
  int x = -1;
  if (t.count(n + 1)) {
    x = n + 1;
  } else {
    x = 0;
  }
  while (true) {
    for (auto &v : h[x]) {
      if (!t.count(v)) {
        printf("%d ", v);
      }
    }
    int f = 0;
    for (auto &v : h[x]) {
      if (t.count(v)) {
        printf("%d ", v);
        x = v;
        f = 1;
        break;
      }
    }
  if (!f) {puts(""); break;}
  }

}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T --) {
    work();
  }
  return 0;
}