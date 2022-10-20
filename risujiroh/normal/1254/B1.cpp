#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> map<Z, int> factorize(Z n) {
  map<Z, int> res;
  for (Z i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

constexpr lint inf = 9e18;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n);
  lint sum = 0;
  for (auto&& e : a) {
    cin >> e;
    sum += e;
  }
  lint res = inf;
  for (const auto& p : factorize(sum)) {
    lint d = p.first;
    lint s = 0;
    V<> v;
    auto fn = [&]() -> lint {
      if (v.empty()) return 0;
      lint t = 0;
      int mi = -1;
      for (int i = 0; i < (int)v.size(); ++i) {
        t += v[i];
        if (2 * t >= d) {
          mi = i;
          break;
        }
      }
      lint res = 0;
      for (int i = 0; i < (int)v.size(); ++i) {
        res += (lint)v[i] * abs(i - mi);
      }
      return res;
    };
    lint crr = 0;
    for (int e : a) {
      if (s + e < d) {
        s += e;
        v.push_back(e);
        continue;
      }
      lint x = d - s;
      if (x) {
        e -= x;
        s += x;
        v.push_back(x);
      }
      crr += fn();
      s = 0;
      // V<lint>().swap(v);
      v.clear();
      e %= d;
      if (e) {
        s += e;
        v.push_back(e);
      }
    }
    crr += fn();
    res = min(res, crr);
  }
  cout << (res < inf ? res : -1) << '\n';
}