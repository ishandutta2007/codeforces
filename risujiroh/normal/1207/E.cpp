#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cout << '?';
  for (int a = 1; a <= 100; ++a) {
    cout << ' ' << a;
  }
  cout << endl;
  int x; cin >> x;
  int res = x >> 7 << 7;

  cout << '?';
  for (int a = 1; a <= 100; ++a) {
    cout << ' ' << (a << 7);
  }
  cout << endl;
  cin >> x;
  res |= x & 127;

  cout << "! " << res << endl;
}