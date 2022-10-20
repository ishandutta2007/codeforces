#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  VI p(n); for (int i = 0; i < n; i++) cin >> p[i];
  VI c(n); for (int i = 0; i < n; i++) cin >> c[i];
  struct knight { int i, p, c; };
  vector<knight> ks(n);
  for (int i = 0; i < n; i++) {
    ks[i] = knight({i, p[i], c[i]});
  }
  auto comp = [](auto x, auto y) {
    return x.p < y.p;
  };
  sort(ks.begin(), ks.end(), comp);
  vector<lint> res(n);
  multiset<int, greater<int> > mc;
  for (int i = 0; i < n; i++) {
    res[ks[i].i] = ks[i].c;
    auto itr = mc.begin();
    for (int j = 0; j < min(k, i); j++) {
      res[ks[i].i] += *itr;
      itr++;
    }
    mc.insert(ks[i].c);
  }
  for (auto&& i : res) {
    cout << i << ' ';
  }
  cout << '\n';
  return 0;
}