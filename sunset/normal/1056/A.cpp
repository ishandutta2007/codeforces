#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(100);
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    while (s--) {
      int x;
      cin >> x;
      ++a[x - 1];
    }
  }
  for (int i = 0; i < 100; ++i) {
    if (a[i] == n) {
      printf("%d ", i + 1);
    }
  }
  puts("");
  return 0;
}