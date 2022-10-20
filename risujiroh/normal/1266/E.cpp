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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  int q;
  cin >> q;
  map< pair<int, int>, int> mp;
  long long res = accumulate(begin(a), end(a), 0LL);
  auto b = a;
  while (q--) {
    int s, t, u;
    cin >> s >> t >> u;
    --s, --u;
    if (mp.count({s, t})) {
      if (++b[mp[{s, t}]] > 0) {
        ++res;
      }
      mp.erase({s, t});
    }
    if (u != -1) {
      mp[{s, t}] = u;
      if (b[u] > 0) {
        --res;
      }
      --b[u];
    }
    DEBUG(mp);
    cout << res << '\n';
  }
}