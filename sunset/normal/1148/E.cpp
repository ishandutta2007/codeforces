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
  vector<pair<int, int>> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i].first;
    s[i].second = i + 1;
  }
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for (int i = 0; i < n; ++i) {
    s[i].first -= t[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += s[i].first;
  }
  auto no_solution = [&]() {
    cout << "NO" << "\n";
    exit(0);
  };
  if (sum != 0) {
    no_solution();
    cout << "NO" << "\n";
  }
  vector<pair<pair<int, int>, int>> ans;
  int i = 0, j = 0;
  while (true) {
    while (i < n && s[i].first >= 0) {
      ++i;
    }
    while (j < n && s[j].first <= 0) {
      ++j;
    }
    if (i == n) {
      break;
    }
    if (i > j) {
      no_solution();
    }
    int take = min(-s[i].first, s[j].first);
    ans.emplace_back(make_pair(s[i].second, s[j].second), take);
    s[i].first += take;
    s[j].first -= take;
  }
  cout << "YES" << "\n";
  cout << ans.size() << "\n";
  for (auto p : ans) {
    cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
  }
  return 0;
}