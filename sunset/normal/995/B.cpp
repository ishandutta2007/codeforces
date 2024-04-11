#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> a(n, make_pair(-1, -1));
  for (int i = 0; i < n << 1; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    if (~a[x].first) {
      a[x].second = i;
    } else {
      a[x].first = i;
    }
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      pair<int, int> x = a[i], y = a[j];
      if (x.first > y.first) {
        swap(x, y);
      }
      if (x.second > y.second) {
        answer += 2;
      } else if (x.second > y.first) {
        ++answer;
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}