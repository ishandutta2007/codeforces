#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define DEBUG(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template <class Z> Z rng(Z l, Z r) {
  return uniform_int_distribution<Z>(l, r - 1)(mt);
}

struct rolling_hash {
  static constexpr uint64_t mod = 2e9 + 33;
  static long long base[2];
  static vector<int> powb[2];
  vector<int> h[2];
  template <class S = string> rolling_hash(const S& s = "") : h{{0}, {0}} {
    assert(all_of(begin(s), end(s), [](uint64_t c) { return c < mod; }));
    for (int k : {0, 1}) {
      for (auto c : s) h[k].push_back((h[k].back() * base[k] + c) % mod);
      while (powb[k].size() <= s.size())
        powb[k].push_back(powb[k].back() * base[k] % mod);
    }
  }
  int get(int l, int r, int k) const {
    return (h[k][r] + (mod - h[k][l]) * powb[k][r - l]) % mod;
  }
  auto get(int l, int r) const { return make_pair(get(l, r, 0), get(l, r, 1)); }
  int size() const { return h[0].size() - 1; }
};
long long rolling_hash::base[]{rng<int>(1e9, 2e9), rng<int>(1e9, 2e9)};
vector<int> rolling_hash::powb[]{{1}, {1}};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    rolling_hash rh(s), rev(string(rbegin(s), rend(s)));
    int mx = -1, ml = -1, mr = -1;
    for (int t : {0, 1}) {
      int prv = (n & 1) - 2;
      for (int l = n / 2; l >= 0; --l) {
        int cur = prv + 2;
        while (rh.get(l, l + cur) != rev.get(n - (l + cur), n - l)) {
          --cur;
        }
        DEBUG(l, cur);
        if (rh.get(0, l) == rev.get(0, l) and 2 * l + cur > mx) {
          mx = 2 * l + cur;
          ml = l + cur, mr = n - l;
          if (t) {
            tie(ml, mr) = make_pair(n - mr, n - ml);
          }
          DEBUG(t, mx, ml, mr);
        }
        prv = cur;
      }
      reverse(begin(s), end(s));
      swap(rh, rev);
    }
    cout << s.substr(0, ml) + s.substr(mr) << '\n';
  }
}