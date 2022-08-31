#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int b, k;
  cin >> b >> k;
  int ans = 0;
  while (k--) {
    int x;
    cin >> x;
    ans = (ans * b + x) % 2;
  }
  cout << (ans ? "odd" : "even") << "\n";
  return 0;
}