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
  cerr << ' ' << to_string(head), debug(tail...);
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
  string s;
  cin >> s;
  int n = s.size();
  struct query {
    int id, k;
    string m;
    pair<int, int> h;
    bool operator<(const query& b) const {
      return h < b.h;
    }
  };
  int q;
  cin >> q;
  vector<vector<query>> qry(n + 1);
  for (int id = 0; id < q; ++id) {
    int k;
    string m;
    cin >> k >> m;
    qry[m.size()].push_back({id, k, m, rolling_hash(m).get(0, m.size())});
  }
  rolling_hash rh(s);
  vector<int> res(q);
  for (int l = 1; l <= n; ++l) {
    if (qry[l].empty()) {
      continue;
    }
    sort(begin(qry[l]), end(qry[l]));
    int sz = qry[l].size();
    vector<vector<int>> idx(sz);
    for (int i = 0; i + l <= n; ++i) {
      auto h = rh.get(i, i + l);
      auto it = lower_bound(begin(qry[l]), end(qry[l]), h, [](const auto& a, const auto& b) {
        return a.h < b;
      });
      if (it == end(qry[l]) or it->h != h) {
        continue;
      }
      idx[it - begin(qry[l])].push_back(i);
    }
    for (int j = 0; j < sz; ++j) {
      DEBUG(qry[l][j].m, idx[j]);
      int mn = n + 1;
      int w = qry[l][j].k - 1;
      for (int t = 0; t + w < (int)idx[j].size(); ++t) {
        mn = min(mn, idx[j][t + w] - idx[j][t] + l);
      }
      res[qry[l][j].id] = mn <= n ? mn : -1;
    }
  }
  for (auto e : res) {
    cout << e << '\n';
  }
}