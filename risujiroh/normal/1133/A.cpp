#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  char c;
  int h0, m0; cin >> h0 >> c >> m0;
  int h1, m1; cin >> h1 >> c >> m1;
  int x = 60 * (h0 + h1) + m0 + m1 >> 1;
  int h = x / 60, m = x % 60;
  cout << setfill('0') << setw(2) << h;
  cout << ':';
  cout << setfill('0') << setw(2) << m;
  cout << '\n';
}