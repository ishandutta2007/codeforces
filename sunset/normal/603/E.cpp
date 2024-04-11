#include <bits/stdc++.h>

using namespace std;

struct edge {
  int from, to, cost, id;

  bool operator<(const edge& o) const {
    return cost < o.cost;
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<edge> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i].from >> e[i].to >> e[i].cost;
    --e[i].from; --e[i].to;
    e[i].id = i;
  }
  vector<edge> sorted_e = e;
  sort(sorted_e.begin(), sorted_e.end());
  for (int i = 0; i < m; ++i) {
    e[sorted_e[i].id].cost = i;
  }
  vector<int> p(n);
  vector<int> s(n);
  int odd = n;
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    s[i] = 1;
  }
  vector<int> ans(m);
  stack<pair<int*, int>> stk;
  auto find = [&](int v) {
    while (v != p[v]) {
      v = p[v];
    }
    return v;
  };
  auto unite = [&](int v, int u) {
    v = find(v); u = find(u);
    if (v != u) {
      if (s[v] > s[u]) {
        swap(v, u);
      }
      if ((s[v] & 1) && (s[u] & 1)) {
        stk.emplace(&odd, odd);
        odd -= 2;
      }
      stk.emplace(&p[v], p[v]);
      p[v] = u;
      stk.emplace(&s[u], s[u]);
      s[u] += s[v];
    }
  };
  auto roll_back = [&](int t) {
    while ((int) stk.size() > t) {
      *stk.top().first = stk.top().second;
      stk.pop();
    }
  };
  function<void(int, int, int, int)> solve = [&](int l, int r, int ll, int rr) {
    if (l > r) {
      return;
    }
    if (ll == rr) {
      for (int i = l; i <= r; ++i) {
        ans[i] = ll;
      }
      return;
    }
    int y = (l + r) >> 1;
    int t = stk.size();
    ans[y] = rr;
    for (int i = l; i <= y; ++i) {
      if (e[i].cost < ll) {
        unite(e[i].from, e[i].to);
      }
    }
    for (int i = ll; i < rr; ++i) {
      if (sorted_e[i].id <= y) {
        unite(sorted_e[i].from, sorted_e[i].to);
        if (!odd) {
          ans[y] = i;
          break;
        }
      }
    }
    roll_back(t);
    for (int i = ll; i < ans[y]; ++i) {
      if (sorted_e[i].id < l) {
        unite(sorted_e[i].from, sorted_e[i].to);
      }
    }
    solve(l, y - 1, ans[y], rr);
    roll_back(t);
    for (int i = l; i <= y; ++i) {
      if (e[i].cost < ll) {
        unite(e[i].from, e[i].to);
      }
    }
    solve(y + 1, r, ll, ans[y]);
    roll_back(t);
  };
  solve(0, m - 1, 0, m);
  for (int i = 0; i < m; ++i) {
    if (ans[i] == m) {
      cout << -1 << "\n";
    } else {
      cout << sorted_e[ans[i]].cost << "\n";
    }
  }
  return 0;
}