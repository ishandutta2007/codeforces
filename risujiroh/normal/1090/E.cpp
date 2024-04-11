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
  VV<> id{
    { 1, 48, 31, 50, 33, 16, 63, 18},
    {30, 51, 46,  3, 62, 19, 14, 35},
    {47,  2, 49, 32, 15, 34, 17, 64},
    {52, 29,  4, 45, 20, 61, 36, 13},
    { 5, 44, 25, 56,  9, 40, 21, 60},
    {28, 53,  8, 41, 24, 57, 12, 37},
    {43,  6, 55, 26, 39, 10, 59, 22},
    {54, 27, 42,  7, 58, 23, 38, 11}
  };
  for (int x = 0; x < 8; ++x) for (int y = 0; y < 8; ++y) --id[x][y];
  auto s2id = [&](const string& s) -> int {
    return id[s[0] - 'a'][s[1] - '1'];
  };
  auto id2s = [&](int i) -> string {
    for (int x = 0; x < 8; ++x) for (int y = 0; y < 8; ++y) if (id[x][y] == i) {
      return {'a' + x, '1' + y};
    }
  };
  int n; cin >> n;
  V<> a(64);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    ++a[s2id(s)];
  }
  V<> b(64);
  for (int y = 0; y < 8; ++y) for (int x = 0; x < 8; ++x) {
    if (n-- > 0) ++b[s2id({'a' + x, '1' + y})];
  }
  int i = 0, j = 0;
  V<string> res;
  for (int i = 62; i >= 0; --i) for (int j = i; j + 1 < 64; ++j) {
    if (a[j] and !a[j + 1]) {
      res.push_back(id2s(j) + '-' + id2s(j + 1));
      swap(a[j], a[j + 1]);
    }
  }
  while (a != b) {
    while (i < 64 and !a[i]) ++i;
    while (j < 64 and !b[j]) ++j;
    if (i == 64) break;
    if (i > j) {
      for (int k = i - 1; k >= j; --k) {
        res.push_back(id2s(k + 1) + '-' + id2s(k));
      }
      swap(a[i], a[j]);
    }
    if (i < j) {
      break;
    }
    ++i, ++j;
  }
  i = j = 63;
  while (a != b) {
    while (i >= 0 and !a[i]) --i;
    while (j >= 0 and !b[j]) --j;
    if (i == 0) break;
    if (i < j) {
      for (int k = i; k < j; ++k) {
        res.push_back(id2s(k) + '-' + id2s(k + 1));
      }
      swap(a[i], a[j]);
    }
    if (i > j) assert(false);
    --i, --j;
  }
  cout << res.size() << '\n';
  for (const auto& e : res) {
    cout << e << '\n';
  }
}