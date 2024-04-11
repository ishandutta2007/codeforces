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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 1) {
        l[i + 1] = l[i] + 1;
      } else {
        l[i + 1] = l[i] - 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      cin >> r[n - i];
      if (r[n - i] == 2) {
        r[n - i] = -1;
      }
    }
    for (int i = 0; i < n; ++i) {
      r[i + 1] += r[i];
    }
    DEBUG(l);
    DEBUG(r);
    map< int, vector<int> > mp;
    for (int i = 0; i <= n; ++i) {
      mp[r[i]].push_back(i);
    }
    int res = 0;
    for (int i = 0; i <= n; ++i) {
      if (mp.count(-l[i])) {
        res = max(res, i + mp[-l[i]].back());
      }
    }
    res = 2 * n - res;
    cout << res << '\n';
  }
}