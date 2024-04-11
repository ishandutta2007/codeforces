#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, B, A; cin >> n >> B >> A;
  V<> s(n); for (auto&& e : s) cin >> e;
  int i = 0;
  int b = B, a = A;
  while (b > 0 or a > 0) {
    if (s[i]) {
      if (b and a < A) --b, ++a;
      else if (a) --a;
      else if (b) --b;
      else break;
    } else {
      if (a) --a;
      else if (b) --b;
      else break;
    }
    ++i;
    if (i == n) break;
  }
  cout << i << '\n';
}