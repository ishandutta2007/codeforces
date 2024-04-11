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
  string s; cin >> s;
  int m = n / 3;
  int c0 = count(begin(s), end(s), '0');
  int c1 = count(begin(s), end(s), '1');
  int c2 = count(begin(s), end(s), '2');
  if (c0 > m and c1 <= m and c2 <= m) {
    int a1 = m - c1, a2 = m - c2;
    for (int i = n - 1; i >= 0; --i) if (s[i] == '0') {
      if (a2) {
        s[i] = '2';
        --a2;
      } else if (a1) {
        s[i] = '1';
        --a1;
      }
    }
  } else if (c1 > m and c0 <= m and c2 <= m) {
    int a0 = m - c0, a2 = m - c2;
    for (int i = 0; i < n; ++i) if (s[i] == '1') {
      if (a0) {
        s[i] = '0';
        --a0;
      }
    }
    for (int i = n - 1; i >= 0; --i) if (s[i] == '1') {
      if (a2) {
        s[i] = '2';
        --a2;
      }
    }
  } else if (c2 > m and c0 <= m and c1 <= m) {
    int a0 = m - c0, a1 = m - c1;
    for (int i = 0; i < n; ++i) if (s[i] == '2') {
      if (a0) {
        s[i] = '0';
        --a0;
      } else if (a1) {
        s[i] = '1';
        --a1;
      }
    }
  } else if (c0 < m and c1 >= m and c2 >= m) {
    int a1 = c1 - m, a2 = c2 - m;
    for (int i = 0; i < n; ++i)  if (s[i] == '2') {
      if (a2) {
        s[i] = '0';
        --a2;
      }
    }
    for (int i = 0; i < n; ++i)  if (s[i] == '1') {
      if (a1) {
        s[i] = '0';
        --a1;
      }
    }
  } else if (c1 < m and c0 >= m and c2 >= m) {
    int a0 = c0 - m, a2 = c2 - m;
    for (int i = 0; i < n; ++i) if (s[i] == '2') {
      if (a2) {
        s[i] = '1';
        --a2;
      }
    }
    for (int i = n - 1; i >= 0; --i) if (s[i] == '0') {
      if (a0) {
        s[i] = '1';
        --a0;
      }
    }
  } else if (c2 < m and c0 >= m and c1 >= m) {
    int a0 = c0 - m, a1 = c1 - m;
    for (int i = n - 1; i >= 0; --i) if (s[i] == '0') {
      if (a0) {
        s[i] = '2';
        --a0;
      }
    }
    for (int i = n - 1; i >= 0; --i) if (s[i] == '1') {
      if (a1) {
        s[i] = '2';
        --a1;
      }
    }
  }
  cout << s << '\n';
}