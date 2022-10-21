#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  V<> h(n + 1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') h[i + 1] = h[i] + 1;
    else h[i + 1] = h[i] - 1;
  }
  int mx = *max_element(begin(h), end(h));
  for (int i = 0; i < n; ++i) {
    cout << (max(h[i], h[i + 1]) > mx / 2);
  }
  cout << '\n';
}