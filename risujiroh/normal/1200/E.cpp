#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> Z rng(Z a, Z b) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<Z>(a, b - 1)(mt);
}

struct RollingHash {
  static constexpr uint64_t P0 = 4111144441, P1 = 4111444111;
  static uint64_t B0, B1;
  static V<unsigned> powB0, powB1;
  int n;
  V<unsigned> h0, h1;
  template<class Itr> RollingHash(Itr first, Itr last) : n(distance(first, last)), h0(n + 1), h1(n + 1) {
    for (int i = 0; i < n; ++i, ++first) {
      h0[i + 1] = (h0[i] * B0 + *first) % P0;
      h1[i + 1] = (h1[i] * B1 + *first) % P1;
    }
    while ((int)powB0.size() <= n) {
      powB0.push_back(powB0.back() * B0 % P0);
      powB1.push_back(powB1.back() * B1 % P1);
    }
  }
  void add(const string& s) {
    h0.resize(n + s.size() + 1), h1.resize(n + s.size() + 1);
    for (int i = n; i < n + (int)s.size(); ++i) {
      h0[i + 1] = (h0[i] * B0 + s[i - n]) % P0;
      h1[i + 1] = (h1[i] * B1 + s[i - n]) % P1;
    }
    n += s.size();
    while ((int)powB0.size() <= n) {
      powB0.push_back(powB0.back() * B0 % P0);
      powB1.push_back(powB1.back() * B1 % P1);
    }
  }
  unsigned get0(int l, int r) const { return (h0[r] + (P0 - h0[l]) * powB0[r - l]) % P0; }
  unsigned get1(int l, int r) const { return (h1[r] + (P1 - h1[l]) * powB1[r - l]) % P1; }
  pair<unsigned, unsigned> get(int l, int r) const { return {get0(l, r), get1(l, r)}; }
  template<class Itr> static unsigned get0(Itr first, Itr last) {
    unsigned res = 0;
    while (first != last) {
      res = (res * B0 + *first++) % P0;
    }
    return res;
  }
  template<class Itr> static unsigned get1(Itr first, Itr last) {
    unsigned res = 0;
    while (first != last) {
      res = (res * B1 + *first++) % P1;
    }
    return res;
  }
  template<class Itr> static pair<unsigned, unsigned> get(Itr first, Itr last) {
    return {get0(first, last), get1(first, last)};
  }
};
uint64_t RollingHash::B0 = rng<unsigned>(1, RollingHash::P0);
uint64_t RollingHash::B1 = rng<unsigned>(1, RollingHash::P1);
V<unsigned> RollingHash::powB0{1};
V<unsigned> RollingHash::powB1{1};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s;
  RollingHash rhs(begin(s), end(s));
  while (n--) {
    string t; cin >> t;
    int ns = s.size(), nt = t.size();
    RollingHash rht(begin(t), end(t));

    for (int k = min(ns, nt); k >= 0; --k) {
      if (rhs.get(ns - k, ns) == rht.get(0, k)) {
        s += t.substr(k);
        rhs.add(t.substr(k));
        break;
      }
    }
  }
  cout << s << '\n';
}