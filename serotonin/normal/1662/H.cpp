#include <bits/stdc++.h>

using namespace std;

int t, w, l;

int main() {
  cin >> t;
  while (t--) {
    cin >> w >> l;
    vector <int> ans;
    ans.emplace_back(1);
    ans.emplace_back(2);
    int x = __gcd(w, l - 2); 
    for (int d = 1; d * d <= x; ++d) if (x % d == 0) {
      ans.emplace_back(d);
      if (d * d != x) ans.emplace_back(x / d);
    }
    x = __gcd(w - 2, l);
    for (int d = 1; d * d <= x; ++d) if (x % d == 0) {
      ans.emplace_back(d);
      if (d * d != x) ans.emplace_back(x / d);
    }
    x = __gcd(w - 1, l - 1);
    for (int d = 1; d * d <= x; ++d) if (x % d == 0) {
      ans.emplace_back(d);
      if (d * d != x) ans.emplace_back(x / d);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size();
    for (int x : ans) printf(" %d", x); puts("");
  }
  return 0;
}