#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
    --r[i];
  }
  vector<int> rr(n);
  for (int i = 0; i < n; ++i) {
    rr[r[i]] = i;
  }
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    --c[i];
  }
  vector<int> cc(n);
  for (int i = 0; i < n; ++i) {
    cc[c[i]] = i;
  }
  vector<vector<int>> ans;
  for (int i = 0; i < n; ++i) {
    int j = rr[i];
    int k = cc[i];
    if (j != i || k != i) {
      ans.push_back({j, i, i, k});
      swap(r[i], r[j]);
      swap(rr[r[i]], rr[r[j]]);
      swap(c[i], c[k]);
      swap(cc[c[i]], cc[c[k]]);
    }
  }
  cout << ans.size() << "\n";
  for (auto v : ans) {
    cout << v[0] + 1 << " " << v[1] + 1 << " " << v[2] + 1 << " " << v[3] + 1 << "\n";
  }
  return 0;
}