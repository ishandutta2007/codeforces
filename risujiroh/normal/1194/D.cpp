#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    bool ok = true;
    if (k % 3) {
      if (!(n % 3)) ok = false;
    } else {
      n %= k + 1;
      if (n < k and !(n % 3)) ok = false;
    }
    cout << (ok ? "Alice" : "Bob") << '\n';
  }
}