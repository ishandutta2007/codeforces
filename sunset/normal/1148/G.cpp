#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = *max_element(a.begin(), a.end());
  vector<int> mu(m + 1), minp(m + 1);
  vector<int> primes;
  mu[1] = 1;
  for (int i = 2; i <= m; ++i) {
    if (!minp[i]) {
      minp[i] = i;
      mu[i] = -1;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > m) {
        break;
      }
      minp[i * p] = p;
      if (i % p == 0) {
        break;
      } else {
        mu[i * p] = -mu[i];
      }
    }
  }
  vector<vector<int>> p(n);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x != 1) {
      int q = minp[x];
      p[i].push_back(q);
      while (x % q == 0) {
        x /= q;
      }
    }
  }
  vector<int> cnt(m + 1);
  vector<int> mis, non_mis;
  function<void(int, int, int)> add = [&](int i, int x, int v) {
    if (x == (int) p[i].size()) {
      cnt[v] += mu[v];
    } else {
      add(i, x + 1, v);
      add(i, x + 1, v * p[i][x]);
    }
  };
  function<void(int, int, int)> clear = [&](int i, int x, int v) {
    if (x == (int) p[i].size()) {
      cnt[v] = 0;
    } else {
      clear(i, x + 1, v);
      clear(i, x + 1, v * p[i][x]);
    }
  };
  function<int(int, int, int)> query = [&](int i, int x, int v) {
    if (x == (int) p[i].size()) {
      return cnt[v];
    } else {
      return query(i, x + 1, v) + query(i, x + 1, v * p[i][x]);
    }
  };
  for (int i = 0; i < n; ++i) {
    if (!query(i, 0, 1)) {
      add(i, 0, 1);
      mis.push_back(i);
    } else {
      non_mis.push_back(i);
    }
  }
  for (auto i : mis) {
    clear(i, 0, 1);
  }
  if ((int) mis.size() >= k) {
    for (int i = 0; i < k; ++i) {
      if (i) {
        cout << " ";
      }
      cout << mis[i] + 1;
    }
    cout << "\n";
    return 0;
  }
  vector<vector<int>> adj(mis.size());
  function<void(int, int, vector<int>)> solve = [&](int l, int r, vector<int> q) {
    if (l == r) {
      adj[l] = q;
    } else {
      int mid = (l + r) >> 1;
      vector<int> left, right;
      for (int i = l; i <= mid; ++i) {
        add(mis[i], 0, 1);
      }
      for (auto i : q) {
        if (query(i, 0, 1)) {
          left.push_back(i);
        } else {
          right.push_back(i);
        }
      }
      for (int i = l; i <= mid; ++i) {
        clear(mis[i], 0, 1);
      }
      solve(l, mid, left);
      solve(mid + 1, r, right);
    }
  };
  solve(0, mis.size() - 1, non_mis);
  vector<pair<int, int>> all(mis.size());
  for (int i = 0; i < (int) mis.size(); ++i) {
    all[i] = make_pair((int) adj[i].size(), i);
  }
  sort(all.begin(), all.end(), greater<pair<int, int>>());
  int sum = 0;
  for (int i = 0; i < (int) mis.size(); ++i) {
    sum += all[i].first + 1;
    if (sum >= k) {
      vector<int> take(i + 1, 1);
      int need = k - (i + 1) * 2;
      for (int j = 0; j <= i; ++j) {
        int value = min(all[j].first - take[j], need);
        take[j] += value;
        need -= value;
      }
      vector<int> ans;
      for (int j = 0; j <= i; ++j) {
        ans.push_back(mis[all[j].second]);
        for (int k = 0; k < take[j]; ++k) {
          ans.push_back(adj[all[j].second][k]);
        }
      }
      for (int j = 0; j < k; ++j) {
        if (j) {
          cout << " ";
        }
        cout << ans[j] + 1;
      }
      cout << "\n";
      return 0;
    }
  }
  return 0;
}