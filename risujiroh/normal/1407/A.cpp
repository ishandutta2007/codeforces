#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    array cnt{0, 0};
    while (n--) {
      int a;
      cin >> a;
      ++cnt[a];
    }
    int x = max_element(begin(cnt), end(cnt)) - begin(cnt);
    if (x) cnt[x] &= ~1;
    cout << cnt[x] << '\n';
    for (int i = 0; i < cnt[x]; ++i) cout << x << " \n"[i == cnt[x] - 1];
  }
}