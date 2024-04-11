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
  vector<int> l(n + 1);
  l[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i - 2] < a[i - 1]) {
      l[i] = l[i - 1] + 1;
    } else {
      l[i] = 1;
    }
  }
  vector<int> r(n + 1);
  r[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] < a[i + 1]) {
      r[i] = r[i + 1] + 1;
    } else {
      r[i] = 1;
    }
  }
  DEBUG(l);
  DEBUG(r);
  int res = 0;
  res = max(res, *max_element(begin(l), end(l)));
  res = max(res, *max_element(begin(r), end(r)));
  for (int i = 1; i < n - 1; ++i) {
    if (a[i - 1] < a[i + 1]) {
      res = max(res, l[i] + r[i + 1]);
    }
  }
  cout << res << '\n';
}