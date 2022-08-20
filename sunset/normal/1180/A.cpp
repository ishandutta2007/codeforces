#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  cout << n * n + (n - 1) * (n - 1) << "\n";
  return 0;
}