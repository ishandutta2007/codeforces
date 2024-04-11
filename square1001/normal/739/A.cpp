#include <bits/stdc++.h>
using namespace std;
int n, m, l, r;
int main() {
  scanf("%d%d", &n, &m);
  int ret = 999999999;
  while(m--) {
    scanf("%d%d", &l, &r);
    ret = min(ret, r - l + 1);
  }
  printf("%d\n", ret);
  for(int i = 0, c = 0; i < n; i++) {
    printf(i ? " %d" : "%d", c);
    if(++c == ret) c = 0;
  }
  cout << endl;
  return 0;
}