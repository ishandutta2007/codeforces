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

  auto solve = [](const auto& a) -> int64_t {
    int n = size(a);
    vector<int> prv(n);
    {
      stack<int, vector<int>> stk;
      for (int i = 0; i < n; ++i) {
        while (not empty(stk) and not(a[stk.top()] > a[i])) stk.pop();
        prv[i] = not empty(stk) ? stk.top() : -1;
        stk.push(i);
      }
    }
    vector<int> nxt(n);
    {
      stack<int, vector<int>> stk;
      for (int i = n; i--;) {
        while (not empty(stk) and not(a[i] < a[stk.top()])) stk.pop();
        nxt[i] = not empty(stk) ? stk.top() : n;
        stk.push(i);
      }
    }
    vector<vector<int>> ch(n);
    int root = -1;
    for (int i = 0; i < n; ++i) {
      if (prv[i] == -1 and nxt[i] == n) {
        assert(root == -1);
        root = i;
        continue;
      }
      if (prv[i] == -1) {
        assert(nxt[i] != n);
        ch[nxt[i]].push_back(i);
      } else if (nxt[i] == n) {
        assert(prv[i] != -1);
        ch[prv[i]].push_back(i);
      } else {
        assert(prv[i] != -1 and nxt[i] != n);
        assert(a[prv[i]] != a[nxt[i]]);
        if (a[prv[i]] < a[nxt[i]]) {
          ch[prv[i]].push_back(i);
        } else {
          ch[nxt[i]].push_back(i);
        }
      }
    }
    int64_t res{};
    vector<int> sz(n);
    y_combinator([&](auto&& self, int i) -> void {
      sz[i] = 1;
      for (int j : ch[i]) {
        self(j);
        sz[i] += sz[j];
      }
    })(root);
    for (int i = 0; i < n; ++i) {
      int64_t cur = a[i].first;
      for (int j : ch[i]) cur *= sz[j] + 1;
      res += cur;
    }
    return res;
  };

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; ++i) d[i] = abs(a[i + 1] - a[i]);

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    vector<pair<int, int>> p;
    p.reserve(r - l);
    for (int i = l; i < r; ++i) p.emplace_back(d[i], i);
    cout << solve(p) << '\n';
  }
}