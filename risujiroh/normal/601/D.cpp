#include <bits/extc++.h>

template <class F>
struct y_combinator : private F {
  y_combinator(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> offset(n);
  for (auto&& e : offset) cin >> e;
  string s;
  cin >> s;
  vector<vector<int>> g(n);
  for (int _ = n - 1; _--;) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  struct node {
    array<node*, 26> ch;
    int sz = 1;
  };

  y_combinator merge = [&](auto&& self, node* a, node* b) -> void {
    for (int i = 0; i < 26; ++i) {
      if (b->ch[i] == nullptr) continue;
      if (a->ch[i]) {
        a->sz -= a->ch[i]->sz;
        self(a->ch[i], b->ch[i]);
        a->sz += a->ch[i]->sz;
      } else {
        a->ch[i] = b->ch[i];
        a->sz += b->ch[i]->sz;
      }
    }
  };

  int mx = -1, cnt;
  y_combinator([&](auto&& self, int v, int p) -> node* {
    auto t = new node{};
    for (int u : g[v]) {
      if (u == p) continue;
      auto&& c = t->ch[s[u] - 'a'];
      if (c) {
        t->sz -= c->sz;
        merge(c, self(u, v));
        t->sz += c->sz;
      } else {
        c = self(u, v);
        t->sz += c->sz;
      }
    }
    int cur = offset[v] + t->sz;
    if (cur > mx) {
      mx = cur;
      cnt = 0;
    }
    cnt += cur == mx;
    return t;
  })(0, -1);

  cout << mx << '\n';
  cout << cnt << '\n';
}