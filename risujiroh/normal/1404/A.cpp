#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    assert(k % 2 == 0);
    string s;
    cin >> s;

    vector zero(k, true), one(k, true);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') one[i % k] = false;
      if (s[i] == '1') zero[i % k] = false;
    }

    bool can = [&] {
      for (int i = 0; i < k; ++i)
        if (not zero[i] and not one[i]) return false;

      array<int, 2> cnt{};
      for (int i = 0; i < k; ++i) {
        cnt[0] += zero[i];
        cnt[1] += one[i];
      }
      return min(cnt[0], cnt[1]) >= k / 2;
    }();

    cout << (can ? "YES\n" : "NO\n");
  }
}