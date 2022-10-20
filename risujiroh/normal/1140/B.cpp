#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    int x = 0;
    while (x < n and s[x] == '<') ++x;
    int y = 0;
    while (y < n and s[n + ~y] == '>') ++y;
    cout << min(x, y) << '\n';
  }
}