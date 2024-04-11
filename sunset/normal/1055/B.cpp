#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, l;
  scanf("%d %d %d", &n, &m, &l);
  vector<long long> a(n);
  int answer = 0;
  auto insert = [&](int x) {
    if (!x || a[x - 1] <= l) {
      ++answer;
    }
    if (x + 1 < n && a[x + 1] > l) {
      --answer;
    }
  };
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] > l) {
      insert(i);
    }
  }
  while (m--) {
    int type;
    scanf("%d", &type);
    if (!type) {
      printf("%d\n", answer);
    } else {
      int pos, add;
      scanf("%d %d", &pos, &add);
      --pos;
      if (a[pos] <= l && a[pos] + add > l) {
        insert(pos);
      }
      a[pos] += add;
    }
  }
  return 0;
}