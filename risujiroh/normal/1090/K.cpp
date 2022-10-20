#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  map< pair<string, int>, V<> > mp;
  for (int i = 0; i < n; ++i) {
    string s, t; cin >> s >> t;
    int bit = 0;
    for (char c : t) {
      bit |= 1 << c - 'a';
    }
    while (!s.empty() and bit & 1 << s.back() - 'a') s.pop_back();
    mp[{s, bit}].push_back(i);
  }
  cout << mp.size() << '\n';
  for (const auto& e : mp) {
    cout << e.second.size();
    for (int i : e.second) {
      cout << ' ' << i + 1;
    }
    cout << '\n';
  }
}