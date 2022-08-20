#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    a[i * i % m] += n / m + (i <= n % m);
  }
  --a[0];
  long long answer = (long long)a[0] * a[0];
  for (int i = 1; i < m; ++i) {
    answer += (long long)a[i] * a[m - i];
  }
  cout << answer << endl;
  return 0;
}