#include <bits/stdc++.h>

const int N = 2005;

int n, ans;

int query(int w) {
  printf("? %d\n", w); fflush(stdout);
  int h; scanf("%d", &h);
  return h;
}

int main() {
  std::cin >> n;
  int l = 1, r = 4001999, w1;
  while (l <= r) {
  	int mid = l + r >> 1;
  	if (query(mid) == 1) w1 = mid, r = mid - 1;
  	else l = mid + 1;
  }
  ans = w1;
  for (int i = 2; i <= n; i++)
    if (query(w1 / i) == i && w1 / i * i < ans)
      ans = w1 / i * i;
  return printf("! %d\n", ans), 0;
}