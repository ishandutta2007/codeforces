#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int Q; cin >> Q;
  while (Q--) {
    int n; cin >> n;
    V<> a(4 * n);
    map<int, int> mp;
    for (auto&& e : a) {
      cin >> e;
      ++mp[e];
    }
    bool ok = true;
    V<> v;
    for (const auto& e : mp) {
      if (e.second & 1) {
        ok = false;
        break;
      }
      for (int i = 0; i < e.second / 2; ++i) {
        v.push_back(e.first);
      }
    }
    if (ok) {
      assert(v.size() == 2 * n);
      int p = v[0] * v.back();
      for (int i = 0; i < n; ++i) {
        if (v[i] * v[2 * n + ~i] != p) {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}