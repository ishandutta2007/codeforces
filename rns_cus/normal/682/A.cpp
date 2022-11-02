#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
  //freopen("in.txt", "r", stdin);
  int n, m;
  long long ans = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) cnt[i % 5]++;
  for (int i = 1; i <= n; i++) {
    int r = i % 5;
    ans += cnt[(5 - r) % 5];
  }
  cout << ans << endl;
}