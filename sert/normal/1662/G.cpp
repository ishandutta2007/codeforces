#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Graph {
  void read() {
    cin >> n;
    es.assign(n, vector<int>(0));
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      x--;
      es[i].push_back(x);
      es[x].push_back(i);
    }
  }
  ll solve() {
    sz.assign(n, 0);
    int centroid = dfs_find(0, -1, true);
    dfs_find(centroid, -1, false);
    ll ans_subtree = accumulate(sz.begin(), sz.end(), 0ll);
    ll mid = calc_best_mid(centroid);
    ll ans_through = mid * (n - 1 - mid);
    return ans_subtree + ans_through;
  }
private:
  int n{};
  vector<vector<int>> es;
  vector<int> sz;
  static constexpr int N = static_cast<int>(1e6 + 2);

  int dfs_find(int v, int pr, bool exit_on_find) {
    int top_sz = n - 1;
    sz[v] = 1;
    int mx = 0;
    for (int w : es[v]) {
      if (w == pr) continue;
      int x = dfs_find(w, v, exit_on_find);
      if (x != -1) {
        return x;
      }
      sz[v] += sz[w];
      top_sz -= sz[w];
      mx = max(mx, sz[w]);
    }
    mx = max(mx, top_sz);
    return (mx <= n / 2 && exit_on_find ? v : -1);
  }

  [[nodiscard]] int calc_best_mid(int centroid) const {
    vector<int> cnt(N, 0);
    int sum = 0;
    for (int w : es[centroid]) {
      cnt[sz[w]]++;
      sum += sz[w];
    }
    assert(sum == n - 1);
    for (int i = 1; i * 2 < N; i++) {
      int to_move = (cnt[i] - 1) / 2;
      cnt[i] -= to_move * 2;
      cnt[i * 2] += to_move;
    }
    bitset<N> bs;
    bs.set(0);
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        bs |= (bs << i);
      }
    }
    for (int i = (n - 1) / 2; i <= n - 1; i++) {
      if (bs[i]) {
        return i;
      }
    }
    exit(11);
  }
};

void solve() {
  Graph g;
  g.read();
  cout << g.solve() << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef SERT
  freopen("../a.in", "r", stdin);
  solve();
  solve();
#else
  solve();
#endif
}