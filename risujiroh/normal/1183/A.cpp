#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int a; cin >> a;
  for (int n = a; ; ++n) {
    int s = 0;
    for (char c : to_string(n)) {
      s += c - '0';
    }
    if (s & 3) continue;
    cout << n << '\n';
    return 0;
  }
}