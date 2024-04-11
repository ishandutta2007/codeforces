#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    bool ok = false;
    for (char c = '0'; c <= '9'; ++c) {
      s += c;
      V<> a(1, n), b(1, n);
      V<bool> used(n);
      for (int i = 0; i < n; ++i) if (s[b.back()] <= s[i]) {
        b.push_back(i);
        used[i] = true;
      }
      for (int i = n - 1; i >= 0; --i) if (!used[i] and s[i] <= s[a.back()]) {
        a.push_back(i);
      }
      if ((int)a.size() - 1 + (int)b.size() - 1 == n) {
        V<> res(n, 1);
        for (int e : b) if (e < n) res[e] = 2;
        for (int e : res) cout << e;
        cout << '\n';
        ok = true;
        break;
      }
      s.pop_back();
    }
    if (!ok) {
      cout << '-' << '\n';
    }
  }
}