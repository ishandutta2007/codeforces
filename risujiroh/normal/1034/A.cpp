#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T> map<T, int> factor(T n, const V<T>& p) {
  map<T, int> res;
  for (T i : p) {
    while (n % i == 0) res[i]++, n /= i;
    if (i * i > n) break;
  }
  if (n != 1) res[n]++;
  return res;
}

template<class T> inline int ord(T n, int p) { return n % p ? 0 : ord(n / p, p) + 1; }

template<class T> V<T> sieve(T a, T b) {
  a = max((T) 2, a); V<T> res; T q = ceil(sqrt(b));
  V<bool> mem(b - a, true), sub(q - 2, true);
  for (T i = 2; i < q; i++) {
    if (sub[i - 2]) {
      for (T j = max(i, (a + i - 1) / i) * i; j < b; j += i) mem[j - a] = false;
      for (T j = i * i; j < q; j += i) sub[j - 2] = false;
    }
  }
  for (T i = a; i < b; i++) if (mem[i - a]) res.push_back(i);
  return res;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  bool same = true;
  for (int i = 0; i < n - 1; i++) if (a[i] != a[i + 1]) same = false;
  if (same) return cout << -1 << '\n', 0;
  auto gcd = [](int a, int b) { return __gcd(a, b); };
  int d = accumulate(a.begin(), a.end(), 0, gcd);
  for (int i = 0; i < n; i++) a[i] /= d;
  auto p = sieve(2, 4000);
  V< map<int, int> > f(n);
  for (int i = 0; i < n; i++) f[i] = factor(a[i], p);
  map<int, int> mp;
  for (int i = 0; i < n; i++) for (auto&& e : f[i]) mp[e.first]++;
  int mx = 0;
  for (auto&& e : mp) mx = max(mx, e.second);
  cout << n - mx << '\n';
}