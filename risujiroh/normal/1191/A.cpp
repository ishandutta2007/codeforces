#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int x; cin >> x;
  switch (x & 3) {
    case 0: cout << "1 A\n"; break;
    case 1: cout << "0 A\n"; break;
    case 2: cout << "1 B\n"; break;
    case 3: cout << "2 A\n"; break;
  }
}