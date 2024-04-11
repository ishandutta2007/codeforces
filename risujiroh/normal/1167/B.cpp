#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cout << "? 1 2" << endl;
  int a; cin >> a;
  cout << "? 1 3" << endl;
  int b; cin >> b;
  cout << "? 4 5" << endl;
  int c; cin >> c;
  cout << "? 4 6" << endl;
  int d; cin >> d;
  V<> v{4, 8, 15, 16, 23, 42};
  do {
    if (v[0] * v[1] != a) continue;
    if (v[0] * v[2] != b) continue;
    if (v[3] * v[4] != c) continue;
    if (v[3] * v[5] != d) continue;
    cout << '!';
    for (int e : v) cout << ' ' << e;
    cout << endl;
    return 0;
  } while (next_permutation(begin(v), end(v)));
}