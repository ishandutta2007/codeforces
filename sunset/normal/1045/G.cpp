#include <bits/stdc++.h>

using namespace std;

struct fenwick_t {
  vector<int> all, fenw;
  int n;

  void init() {
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    n = all.size();
    fenw.resize(n);
  }

  void modify(int x) {
    x = lower_bound(all.begin(), all.end(), x) - all.begin();
    while (x < n) {
      ++fenw[x];
      x |= x + 1;
    }
  }

  int query(int x) {
    int result = 0;
    while (x >= 0) {
      result += fenw[x];
      x = (x & x + 1) - 1;
    }
    return result;
  }

  int query(int l, int r) {
    return query(upper_bound(all.begin(), all.end(), r) - all.begin() - 1) - query(lower_bound(all.begin(), all.end(), l) - all.begin() - 1);
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> x(n), r(n), q(n), p(n), disc(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &x[i], &r[i], &q[i]);
    disc[i] = q[i];
    p[i] = i;
  }
  sort(disc.begin(), disc.end());
  disc.erase(unique(disc.begin(), disc.end()), disc.end());
  vector<fenwick_t> fenwick(disc.size());
  
  auto id = [&](int x) {
    int p = lower_bound(disc.begin(), disc.end(), x) - disc.begin();
    if (p < disc.size() && disc[p] == x) {
      return p;
    } else {
      return -1;
    }
  };

  for (int i = 0; i < n; ++i) {
    fenwick[id(q[i])].all.push_back(x[i]);
  }
  for (int i = 0; i < disc.size(); ++i) {
    fenwick[i].init();
  }

  sort(p.begin(), p.end(), [&](const int &x, const int &y) {
    return r[x] > r[y];
  });
  long long answer = 0;
  for (auto i : p) {
    for (int j = q[i] - m; j <= q[i] + m; ++j) {
      int p = id(j);
      if (~p) {
        answer += fenwick[p].query(x[i] - r[i], x[i] + r[i]);
      }
    }
    fenwick[id(q[i])].modify(x[i]);
  }
  printf("%lld\n", answer);
  return 0;
}