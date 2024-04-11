#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  map<int, int> f;
  int sum = 0;
  ++f[sum];
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum ^= x;
    sum = min(sum, (1 << m) - 1 ^ sum);
    ++f[sum];
  }
  long long answer = (long long)n * (n + 1) >> 1;
  for (auto p : f) {
    int l = p.second >> 1, r = p.second + 1 >> 1;
    answer -= (long long)l * (l - 1) >> 1;
    answer -= (long long)r * (r - 1) >> 1;
  }
  cout << answer << endl;
  return 0;
}