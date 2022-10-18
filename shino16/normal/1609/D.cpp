#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 2 "main.cpp"


class union_find {
 public:
  union_find(int n) : par(n, -1), count_(n) {}
  int size() const { return par.size(); }
  int count() const { return count_; }
  void clear() {
    fill(par.begin(), par.end(), -1);
    count_ = size();
  }
  int find(int x) { return par[x] < 0 ? x : par[x] = (int)find(par[x]); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y], par[y] = (int)x;
    count_--;
    return true;
  }
  vector<int> groups() {
    vector<int> res(size());
    for (int x = 0; x < size(); x++) res[find(x)]++;
    // res.erase(remove_if(all(res), [](const auto& v) { return v == 0; }),
              // res.end());
    return res;
  }

 private:
  vector<int> par;
  int count_;
};

int n, d, x, y;

int main() {
  scanf("%d%d", &n, &d);
  union_find uf(n);
  int k = 0;
  while (d--) {
    scanf("%d%d", &x, &y), x--, y--;
    if (!uf.unite(x, y)) k++;
    auto gs = uf.groups();
    sort(all(gs), greater<int>());
    printf("%d\n", accumulate(gs.begin(), gs.begin()+k+1, 0) - 1);
  }
}