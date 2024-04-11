#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k & 1) {
      for (char& c : s) c ^= 1;
    }

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      if (k == 0) break;
      if (s[i] == '1') continue;
      --k;
      s[i] ^= 1;
      ++ans[i];
    }

    if (k & 1) {
      s.back() ^= 1;
    }
    ans.back() += k;

    cout << s << '\n';
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
  }
}