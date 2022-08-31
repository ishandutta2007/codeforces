#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    vector<int> sa(n + 1);
    for (int i = 0; i < n; ++i) {
      sa[i + 1] = sa[i] + a[i];
    }
    vector<int> sb(n + 1);
    for (int i = 0; i < n; ++i) {
      sb[i + 1] = sb[i] + b[i];
    }
    for (int i = 0; ; ++i) {
      int r = n + i;
      int take = r - r / 4;
      int ta = take >= i ? i * 100 + sa[take - i] : take * 100;
      int tb = sb[min(take, n)];
      if (ta >= tb) {
        cout << i << "\n";
        break;
      }
    }
  }
  return 0;
}