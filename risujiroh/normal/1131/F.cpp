#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> p(n);
  VV<> ch(n);
  for (int v = 0; v < n; ++v) {
    p[v] = v;
    ch[v] = {v};
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    if (ch[p[x]].size() < ch[p[y]].size()) swap(x, y);
    x = p[x], y = p[y];
    for (int v : ch[y]) {
      p[v] = x;
    }
    ch[x].insert(end(ch[x]), begin(ch[y]), end(ch[y]));
    V<>().swap(ch[y]);
  }
  for (const auto& e : ch) if (!e.empty()) {
    assert(e.size() == n);
    for (int i = 0; i < n; ++i) {
      cout << e[i] + 1 << " \n"[i == n - 1];
    }
  }
}