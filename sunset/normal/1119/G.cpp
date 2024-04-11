#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> cut;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    sum = (sum + a[i]) % n;
    if (i < m - 1) {
      cut.push_back(sum);
    }
  }
  cut.push_back(0);
  cut.push_back(n);
  sort(cut.begin(), cut.end());
  vector<int> group(m);
  for (int i = 0; i < m; ++i) {
    group[i] = cut[i + 1] - cut[i];
  }
  vector<int> ans;
  for (int i = 0, j = 0; i < m; ++i) {
    while (a[i] > 0) {
      ans.push_back(i);
      a[i] -= group[j];
      j = (j + 1) % m;
    }
  }
  while (ans.size() % m) {
    ans.push_back(0);
  }
  cout << ans.size() / m << "\n";
  for (int i = 0; i < m; ++i) {
    cout << group[i] << (i == m - 1 ? "\n" : " ");
  }
  for (int i = 0; i < (int) ans.size(); ++i) {
    cout << ans[i] + 1 << (i % m == m - 1 ? "\n" : " ");
  }
  return 0;
}