#include <bits/stdc++.h>

using namespace std;

int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int result;
  scanf("%d", &result);
  return result;
}

int print(int x) {
  printf("! %d\n", x);
  fflush(stdout);
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  if (n % 4 == 2) {
    print(-1);
  }
  int x = query(1), y = query(n / 2 + 1);
  if (x == y) {
    print(1);
  } else {
    bool lp = x > y;
    int l = 2, r = n / 2;
    while (l <= r) {
      int mid = l + r >> 1, u = query(mid), v = query(n / 2 + mid);
      if (u == v) {
        print(mid);
      } else if (lp == (u > v)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return 0;
}