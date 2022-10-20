#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m, q; cin >> n >> m >> q;
  if (q == 0) return cout << n + m - 1 << '\n', 0;
  struct E { int i, r, c; };
  V<E> a(q); for (int i = 0; i < q; i++) cin >> a[i].r >> a[i].c, a[i].i = i, a[i].r--, a[i].c--;
  VV<> g(q);
  sort(a.begin(), a.end(), [](E x, E y) { return x.r < y.r or x.r == y.r and x.c < y.c; });
  for (int i = 0; i < q - 1; i++) {
    if (a[i].r == a[i + 1].r) g[a[i].i].push_back(a[i + 1].i), g[a[i + 1].i].push_back(a[i].i);
  }
  sort(a.begin(), a.end(), [](E x, E y) { return x.c < y.c or x.c == y.c and x.r < y.r; });
  for (int i = 0; i < q - 1; i++) {
    if (a[i].c == a[i + 1].c) g[a[i].i].push_back(a[i + 1].i), g[a[i + 1].i].push_back(a[i].i);
  }
  int ncc = 0; V<> v(q); queue<int> que;
  for (int i = 0; i < q; i++) {
    if (v[i]) continue;
    ncc++; v[i] = 1; que.push(i);
    while (not que.empty()) {
      int j = que.front(); que.pop();
      for (auto&& k : g[j]) {
        if (v[k]) continue;
        v[k] = 1; que.push(k);
      }
    }
  }
  V<> cn(n, 1), cm(m, 1);
  for (int i = 0; i < q; i++) cn[a[i].r] = 0, cm[a[i].c] = 0;
  int sn = accumulate(cn.begin(), cn.end(), 0), sm = accumulate(cm.begin(), cm.end(), 0);
  cout << ncc - 1 + sn + sm << '\n';
}