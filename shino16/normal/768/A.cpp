#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, a[100000];
int main() {
  scanf("%d", &n);
  rep(i, n) scanf("%d", a + i);
  sort(a, a + n);
  int l = 0; while (l < n && a[l] == a[0]) l++;
  int r = n; while (r && a[r-1] == a[n-1]) r--;
  printf("%d\n", max(0, r-l));
}