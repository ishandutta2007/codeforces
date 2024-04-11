#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = -1e9;
  while (n--) {
    int a;
    cin >> a;
    int x = sqrt(a);
    if (x * x == a) continue;
    ans = max(ans, a);
  }
  cout << ans << '\n';
}