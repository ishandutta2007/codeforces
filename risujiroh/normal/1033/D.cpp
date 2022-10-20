#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr lint mod = 998244353;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

lint rt4(lint x) {
  lint l = 1, r = 4e4;
  while (r - l > 1) {
    lint m = (l + r) / 2;
    lint p = m * m * m * m;
    if (p == x) return m;
    if (p > x) r = m;
    else l = m;
  }
  return -1;
}
lint rt3(lint x) {
  lint l = 1, r = 2e6;
  while (r - l > 1) {
    lint m = (l + r) / 2;
    lint p = m * m * m;
    if (p == x) return m;
    if (p > x) r = m;
    else l = m;
  }
  return -1;
}
lint rt2(lint x) {
  lint l = 1, r = 2e9;
  while (r - l > 1) {
    lint m = (l + r) / 2;
    lint p = m * m;
    if (p == x) return m;
    if (p > x) r = m;
    else l = m;
  }
  return -1;
}

int main() {
  int n; cin >> n;
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<bool> chk(n, true);
  map<lint, int> mp;
  for (int i = 0; i < n; i++) {
    if (rt4(a[i]) != -1) mp[rt4(a[i])] += 4;
    else if (rt3(a[i]) != -1) mp[rt3(a[i])] += 3;
    else if (rt2(a[i]) != -1) mp[rt2(a[i])] += 2;
    else chk[i] = false;
  }
  map<lint, int> other;
  for (int i = 0; i < n; i++) if (!chk[i]) {
    for (int j = 0; j < n; j++) {
      lint d = __gcd(a[i], a[j]);
      if (d != 1 and d != a[i]) {
        mp[d]++;
        mp[a[i] / d]++;
        chk[i] = true;
        break;
      }
    }
    if (!chk[i]) other[a[i]]++;
  }
  lint res = 1;
  for (auto&& e : mp) (res *= e.second + 1) %= mod;
  for (auto&& e : other) (res *= (e.second + 1) * (e.second + 1)) %= mod;
  cout << emod(res) << endl;
}