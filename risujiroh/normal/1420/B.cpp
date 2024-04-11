#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int64_t ans{};
    vector<int> cnt(30);
    while (n--) {
      int a;
      cin >> a;
      ans += cnt[__lg(a)]++;
    }
    cout << ans << '\n';
  }
}