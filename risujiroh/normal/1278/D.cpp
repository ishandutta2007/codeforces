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

struct UnionFind {
  vector<int> t;
  UnionFind(int n) : t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    --l[i], --r[i];
  }
  vector<int> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return l[i] < l[j]; });
  UnionFind uf(n);
  map<int, int> mp;
  for (int i : idx) {
    auto it = mp.lower_bound(l[i]);
    while (it != end(mp) and it->first < r[i]) {
      if (uf.find(i) == uf.find(it->second)) {
        cout << "NO\n";
        return 0;
      }
      DEBUG(i, it->second);
      uf.unite(i, it->second);
      ++it;
    }
    mp[r[i]] = i;
  }
  if (uf.size(0) == n) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}