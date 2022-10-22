#include <bits/stdc++.h>

int n;

int query(int xl, int xr, int yl, int yr) {
  int ans;
  printf("? %d %d\n", xr - xl + 1, yr - yl + 1);
  for (int i = xl; i <= xr; i++) printf("%d ", i);
  puts("");
  for (int i = yl; i <= yr; i++) printf("%d ", i);
  puts("\n");
  return fflush(stdout), scanf("%d", &ans), ans;
}

void work() {
  scanf("%d", &n);
  std::vector<int> ans;
  int x = 1, tmp, z;
  while (!(tmp = query(x, x, x + 1, n))) x++;
  for (int i = x + 1; i < n; i++)
    if (!(z = query(x, x, i, i))) ans.push_back(i);
	else tmp -= z;
  if (!tmp) ans.push_back(n);
  if (x > 1) {
  	int l = 1, r = x - 1;
  	while (l <= r) {
  	  int mid = l + r >> 1;
  	  if (query(1, mid, x, x)) r = mid - 1;
  	  else l = mid + 1;
	}
	for (int i = 1; i < x; i++)
	  if (i != l) ans.push_back(i);
  }
  else for (int i = 1; i < x; i++) ans.push_back(i);
  printf("! %d ", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  puts(""); fflush(stdout);
}

int main() {
  int T; std::cin >> T;
  while (T--) work();
  return 0;
}