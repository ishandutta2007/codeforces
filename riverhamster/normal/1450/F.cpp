#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int a[N], cnt[N];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    fill(cnt + 1, cnt + 1 + n, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
    if (*max_element(cnt + 1, cnt + 1 + n) > (n + 1) / 2) cout << "-1\n";
    else {
      fill(cnt + 1, cnt + 1 + n, 0);
      int l = a[1], k = 0;
      for (int i = 2; i <= n; ++i)
        if (a[i] == a[i - 1]) {
          ++k; ++cnt[l]; ++cnt[a[i - 1]];
          l = a[i];
        }
      ++cnt[l]; ++cnt[a[n]];
      int res = 0;
      for (int i = 1; i <= n; ++i) res += max(0, cnt[i] - k - 2);
      cout << res + k << '\n';
    }
  }
  return 0;
}