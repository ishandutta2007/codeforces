#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 34;
pair<int, int> a[N];
int n, r = -1, ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &a[i].second, &a[i].first);
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    if (a[i].second > r) {
      r = a[i].first;
      ans++;
    }
  cout << ans;
  return 0;
}