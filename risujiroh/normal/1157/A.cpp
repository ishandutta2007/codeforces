#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  set<int> se;
  auto f = [](int n) -> int {
    ++n;
    while (n % 10 == 0) n /= 10;
    return n;
  };
  while (true) {
    se.insert(n);
    n = f(n);
    if (se.count(n)) break;
  }
  cout << se.size() << '\n';
}