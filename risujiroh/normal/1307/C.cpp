#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<vector<long long>> cnt(26, vector<long long>(26));
  vector<int> t(26);
  for (char c : s) {
    for (int i = 0; i < 26; ++i) {
      cnt[i][c - 'a'] += t[i];
    }
    ++t[c - 'a'];
  }
  long long res = *max_element(begin(t), end(t));
  for (auto e : cnt) {
    res = max(res, *max_element(begin(e), end(e)));
  }
  cout << res << '\n';
}