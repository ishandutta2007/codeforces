#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, s;
  long long t;
  scanf("%d %d %d %lld", &n, &m, &s, &t);
  --s;
  while (t % n) {
    if (s < m) {
      s = (s + t) % n;
    } else {
      s = ((s - t) % n + n) % n;
    }
    --t;
  }
  t /= n;
  vector<long long> visit(n, -1);
  visit[s] = t;
  while (t--) {
    for (int i = n - 1; ~i; --i) {
      if (s < m) {
        s = (s + i) % n;
      } else {
        s = (s + n - i) % n;
      }
    }
    if (~visit[s]) {
      t %= visit[s] - t;
    }
    visit[s] = t;
  }
  printf("%d\n", s + 1);
  return 0;
}