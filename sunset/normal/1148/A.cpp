#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  cout << 2 * (c + min(a, b)) + (a != b) << "\n";
  return 0;
}