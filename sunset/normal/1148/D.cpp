#include <bits/stdc++.h>

using namespace std;

struct point {
  int a, b, i;
};

template<typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int n): n(n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] = max(fenw[x], v);
      x |= x + 1;
    }
  }

  T query(int x) {
    T res{};
    while (x >= 0) {
      res = max(res, fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<point> u, v;
  for (int i = 0; i < n; ++i) {
    point p;
    cin >> p.a >> p.b;
    p.i = i;
    --p.a;
    --p.b;
    if (p.a < p.b) {
      swap(p.a, p.b);
      u.push_back(p);
    } else {
      v.push_back(p);
    }
  }
  auto solve = [&](vector<point> p) {
    if (p.empty()) {
      return vector<int>();
    }
    sort(p.begin(), p.end(), [&](point u, point v) {
      return u.b < v.b;
    });
    int m = p.size();
    vector<int> dp(m), from(m);
    fenwick<pair<int, int>> fenw(n * 2);
    for (int i = 0; i < m; ++i) {
      pair<int, int> v = fenw.query(p[i].a);
      dp[i] = v.first + 1;
      from[i] = v.second;
      fenw.modify(p[i].b, make_pair(dp[i], i));
    }
    int q = max_element(dp.begin(), dp.end()) - dp.begin();
    int take = dp[q];
    vector<int> ans;
    for (int i = 0; i < take; ++i) {
      ans.push_back(p[q].i);
      q = from[q];
    }
    reverse(ans.begin(), ans.end());
    return ans;
  };
  vector<int> ans_u = solve(u), ans_v = solve(v);
  if (ans_u.size() < ans_v.size()) {
    swap(ans_u, ans_v);
  } else {
    reverse(ans_u.begin(), ans_u.end());
  }
  cout << ans_u.size() << "\n";
  for (int i = 0; i < (int) ans_u.size(); ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans_u[i] + 1;
  }
  cout << "\n";
  return 0;
}