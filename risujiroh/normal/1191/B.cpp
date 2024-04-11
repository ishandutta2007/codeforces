#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  VV<string> v;
  for (char c : {'m', 'p', 's'}) {
    for (int i = 1; i <= 9; ++i) {
      v.push_back(V<string>(3, to_string(i) + c));
      if (i + 2 <= 9) {
        v.push_back(V<string>{to_string(i) + c, to_string(i + 1) + c, to_string(i + 2) + c});
      }
    }
  }
  V<string> s(3); cin >> s[0] >> s[1] >> s[2];
  sort(begin(s), end(s));
  int res = 3;
  for (const auto& e : v) {
    V<string> t;
    set_intersection(begin(s), end(s), begin(e), end(e), back_inserter(t));
    int curr = 3 - t.size();
    res = min(res, curr);
  }
  cout << res << '\n';
}