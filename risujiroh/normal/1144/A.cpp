#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    auto t = s;
    sort(begin(t), end(t));
    t.erase(unique(begin(t), end(t)), end(t));
    if (t.size() < s.size()) {
      cout << "No" << '\n';
      continue;
    }
    cout << (t.back() - t[0] + 1 == t.size() ? "Yes" : "No") << '\n';
  }
}