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
  lint n, k, A, B; cin >> n >> k >> A >> B;
  V<lint> a(k); for (int i = 0; i < k; ++i) cin >> a[i], --a[i];
  sort(begin(a), end(a));
  auto rec = [&](const auto& rec, lint l, lint r) -> lint {
    lint x = lower_bound(begin(a), end(a), r) - lower_bound(begin(a), end(a), l);
    if (x == 0) return A;
    if (r - l == 1) return B * x;
    lint m = l + r >> 1;
    return min(B * x * (r - l), rec(rec, l, m) + rec(rec, m, r));
  };
  cout << rec(rec, 0, 1LL << n) << '\n';
}