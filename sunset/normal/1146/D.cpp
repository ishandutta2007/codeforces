#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m, a, b;
  cin >> m >> a >> b;
  vector<int> bound(a + b, -1);
  bound[0] = 0;
  int x = 0, max_bound = 0;
  while (true) {
    if (x >= b) {
      x -= b;
    } else {
      x += a;
    }
    if (!x) {
      break;
    }
    max_bound = max(max_bound, x);
    bound[x] = max_bound;
  }
  long long ans = 0;
  for (int i = 0; i < a + b; ++i) {
    if (bound[i] != -1) {
      ans += max(0, m - bound[i] + 1);
    }
  }
  if (m >= a + b) {
    int g = __gcd(a, b);
    int end = m - (a + b) + 1;
    int begin = end % g;
    ans += (long long) (begin + end) * ((end - begin) / g + 1) / 2;
  }
  cout << ans << "\n";
  return 0;
}