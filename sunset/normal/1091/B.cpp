#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  long long sumx = 0;
  long long sumy = 0;
  for (int i = 0; i < n * 2; ++i) {
    int x, y;
    cin >> x >> y;
    sumx += x;
    sumy += y;
  }
  cout << sumx / n << " " << sumy / n << endl;
  return 0;
}