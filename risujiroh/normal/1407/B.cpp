#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    int g = 0;
    while (not empty(a)) {
      int mi = -1;
      for (int i = 0; i < int(size(a)); ++i)
        if (mi == -1 or gcd(g, a[i]) > gcd(g, a[mi])) mi = i;
      assert(mi != -1);
      cout << a[mi] << " \n"[size(a) == 1];
      g = gcd(g, a[mi]);
      a.erase(begin(a) + mi);
    }
  }
}