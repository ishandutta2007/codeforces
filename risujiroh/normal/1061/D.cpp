#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint mod = 1e9 + 7;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, x, y; cin >> n >> x >> y, x -= y;
  V<> l(n), r(n); for (int i = 0; i < n; ++i) cin >> l[i] >> r[i], --l[i];
  lint res = 0;
  for (int i = 0; i < n; ++i) (res += (lint) (r[i] - l[i]) * y) %= mod;
  struct S { int t, id; };
  V<S> a(2 * n);
  for (int i = 0; i < n; ++i) {
    a[i] = {l[i], 0};
    a[i + n] = {r[i], 1};
  }
  sort(begin(a), end(a), [](const S& lhs, const S& rhs) { return lhs.t != rhs.t ? lhs.t < rhs.t : lhs.id > rhs.id; });
  priority_queue<int> pque;
  for (const auto& e : a) if (e.id) {
    pque.push(e.t);
  } else {
    if (!pque.empty() and (lint) (e.t - pque.top()) * y < x) {
      (res += (lint) (e.t - pque.top()) * y) %= mod;
      pque.pop();
    } else (res += x) %= mod;
  }
  cout << emod(res) << '\n';
}