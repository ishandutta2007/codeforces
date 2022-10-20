#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  string res;
  for (char c : s) {
    int m = res.size();
    if (m & 1 and res.back() == c) continue;
    res += c;
  }
  if (res.size() & 1) res.pop_back();
  cout << n - (int)res.size() << '\n';
  cout << res << '\n';
}