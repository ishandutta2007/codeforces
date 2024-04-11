#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      (i & 1 ? odd : even).push_back(a);
    }
    sort(begin(even), end(even));
    sort(begin(odd), end(odd));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i & 1 ? odd[i / 2] : even[i / 2];
    cout << (is_sorted(begin(a), end(a)) ? "YES\n" : "NO\n");
  }
}