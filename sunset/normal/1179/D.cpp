#include <bits/stdc++.h>

using namespace std;

class my_deque {
  vector<int> a;
  int l = 0;
  int r = 0;

 public:
  void push(int x) {
    a.push_back(x);
    r++;
  }

  void pop_front() {
    l++;
  }

  void pop_back() {
    a.pop_back();
    r--;
  }

  int size() {
    return r - l;
  }

  int front() {
    return a[l];
  }

  int sfront() {
    return a[l + 1];
  }

  int back() {
    return a[r - 1];
  }

  int sback() {
    return a[r - 2];
  }
};

long long square(int x) {
  return (long long) x * x;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  vector<long long> dp(n);
  vector<int> size(n);
  long long ans = square(n);
  function<void(int, int)> dfs = [&](int x, int p) {
    if (p != -1) {
      adj[x].erase(find(adj[x].begin(), adj[x].end(), p));
    }
    size[x] = 1;
    if (adj[x].empty()) {
      dp[x] = 1;
      return;
    }
    dp[x] = square(n);
    for (auto y : adj[x]) {
      dfs(y, x);
      size[x] += size[y];
    }
    sort(adj[x].begin(), adj[x].end());
    for (auto y : adj[x]) {
      dp[x] = min(dp[x], dp[y] + square(size[x] - size[y]));
      ans = min(ans, dp[y] + square(n - size[y]));
    }
    sort(adj[x].begin(), adj[x].end(), [&](int u, int v) {
      return size[u] < size[v] || (size[u] == size[v] && dp[u] > dp[v]);
    });
    my_deque q;
    auto go = [&](int y, int z) {
      return dp[y] + dp[z] + square(n - size[y] - size[z]);
    };
    auto gx = [&](int y) {
      return size[y];
    };
    auto gy = [&](int y) {
      return dp[y] + square(size[y]);
    };
    auto check = [&](int y, int z, int w) {
      return (gx(z) - gx(y)) * (gy(w) - gy(y)) <= (gx(w) - gx(y)) * (gy(z) - gy(y));
    };
    for (auto y : adj[x]) {
      while (q.size() > 1 && go(y, q.front()) >= go(y, q.sfront())) {
        q.pop_front();
      }
      if (q.size()) {
        ans = min(ans, go(y, q.front()));
      }
      while (q.size() > 1 && check(q.sback(), q.back(), y)) {
        q.pop_back();
      }
      q.push(y);
    }
  };
  dfs(0, -1);
  cout << ((long long) n * (2 * n - 1) - ans) / 2 << "\n";
  return 0;
}