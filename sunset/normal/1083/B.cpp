#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  long long answer = 0;
  int ways = 0;
  for (int i = 0; i < n; ++i) {
    ways = min(m, ways * 2 + t[i] - s[i]);
    answer += min(ways + 1, m);
  }
  printf("%lld\n", answer);
  return 0;
}