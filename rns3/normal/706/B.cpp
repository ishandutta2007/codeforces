#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++) scanf("%d", a + i);
  sort(a, a + n);
  int q;
  scanf("%d", &q);
  while(q --) {
    int x;
    scanf("%d", &x);
    int y = upper_bound(a, a + n, x) - a;
    printf("%d\n", y);
  }
}