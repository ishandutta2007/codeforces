#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  constexpr int lim = 1e6 + 30;
  vector<int> cnt(lim);
  while (n--) {
    int w;
    cin >> w;
    ++cnt[w];
  }
  for (int i = 0; i < lim; ++i)
    if (cnt[i]) {
      int q = cnt[i] / 2;
      cnt[i] &= 1;
      cnt[i + 1] += q;
    }
  int ans = count(begin(cnt), end(cnt), 1);
  cout << ans << '\n';
}