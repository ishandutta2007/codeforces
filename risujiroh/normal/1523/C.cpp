#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 1) {
        v.push_back(a);
      } else {
        while (v.back() + 1 != a) v.pop_back();
        ++v.back();
      }
      for (int z = 0; z < int(size(v)); ++z) cout << v[z] << ".\n"[z + 1 == int(size(v))];
    }
  }
}