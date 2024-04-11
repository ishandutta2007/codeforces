#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

V<> sieve(int n) {
  V<bool> b(n / 3 + 1, true);
  V<> res{2, 3};
  for (int p = 5, d = 2; p * p < n; p += d, d = 6 - d) if (b[p / 3]) {
    for (int i = 5 * p, d = 2 * p; i < n; i += d, d = 6 * p - d) b[i / 3] = false;
  }
  for (int p = 5, d = 2; p < n; p += d, d = 6 - d) if(b[p / 3]) res.push_back(p);
  return res;
}
V<> factor;
void init(int n) {
  assert(n > 0);
  factor.resize(n + 1);
  factor[0] = factor[1] = -1;
  for (int p = 2; p * p <= n; ++p) if (factor[p] == 0) {
    for (int i = p * p; i <= n; i += p) if (factor[i] == 0) {
      factor[i] = p;
    }
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  auto p = sieve(2750132);
  init(2750132);
  int n; cin >> n;
  multiset<int> ms;
  V<> cp;
  for (int _ = 0; _ < 2 * n; ++_) {
    int b; cin >> b;
    ms.insert(b);
    if (factor[b]) cp.push_back(b);
  }
  sort(rbegin(cp), rend(cp));
  V<> a;
  for (int e : cp) if (ms.find(e) != end(ms)) {
    a.push_back(e);
    ms.erase(ms.find(e / factor[e]));
    ms.erase(ms.find(e));
  }
  while (!ms.empty()) {
    assert(!factor[*begin(ms)]);
    a.push_back(*begin(ms));
    ms.erase(ms.find(p[*begin(ms) - 1]));
    ms.erase(begin(ms));
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[!(n + ~i)];
}