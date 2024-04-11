#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int la, ra, ta, lb, rb, tb;
  scanf("%d %d %d %d %d %d", &la, &ra, &ta, &lb, &rb, &tb);
  int gcd = __gcd(ta, tb);
  int l0 = la % gcd, r0 = l0 + ra - la;
  int l1 = lb % gcd, r1 = l1 + rb - lb;
  int answer = 0;
  for (int t = -1; t <= 1; ++t) {
    int low = max(l0, l1 + t * gcd), high = min(r0, r1 + t * gcd);
    answer = max(answer, high - low + 1);
  }
  printf("%d\n", answer);
  return 0;
}