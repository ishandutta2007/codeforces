#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  long long n, k;
  cin >> n >> k;
  cout << max(0ll, min(n - (k + 2 >> 1) + 1, k - 1 >> 1)) << endl;
  return 0;
}