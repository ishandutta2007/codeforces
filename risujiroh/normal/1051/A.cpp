#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int t; cin >> t;
  for (int it = 0; it < t; it++) {
    string s; cin >> s;
    int n = s.size();
    int l = 0, u = 0, d = 0;
    for (int i = 0; i < n; i++) {
      if (islower(s[i])) l++;
      if (isupper(s[i])) u++;
      if (isdigit(s[i])) d++;
    }
    int k = !!l + !!u + !!d;
    if (k == 3) cout << s << '\n';
    else if (k == 1) {
      if (l) cout << s.substr(0, n - 2) + "A0" << '\n';
      if (u) cout << s.substr(0, n - 2) + "a0" << '\n';
      if (d) cout << s.substr(0, n - 2) + "aA" << '\n';
    } else {
      if (!l) {
        if (u > d) {
          for (int i = 0; i < n; i++) if (isupper(s[i])) { s[i] = 'a'; break; }
        } else {
          for (int i = 0; i < n; i++) if (isdigit(s[i])) { s[i] = 'a'; break; }
        }
      }
      if (!u) {
        if (l > d) {
          for (int i = 0; i < n; i++) if (islower(s[i])) { s[i] = 'A'; break; }
        } else {
          for (int i = 0; i < n; i++) if (isdigit(s[i])) { s[i] = 'A'; break; }
        }
      }
      if (!d) {
        if (l > u) {
          for (int i = 0; i < n; i++) if (islower(s[i])) { s[i] = '0'; break; }
        } else {
          for (int i = 0; i < n; i++) if (isupper(s[i])) { s[i] = '0'; break; }
        }
      }
      cout << s << '\n';
    }
  }
}