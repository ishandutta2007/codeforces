#include <bits/stdc++.h>

using namespace std;

const int base = 2333;
const int md0 = 1e9 + 7;
const int md1 = 1e9 + 9;

struct hash_t {
  int hash0, hash1;

  hash_t(int hash0 = 0, int hash1 = 0):hash0(hash0), hash1(hash1) {
  }

  hash_t operator + (const int &x) const {
    return hash_t((hash0 + x) % md0, (hash1 + x) % md1);
  };
  
  hash_t operator * (const int &x) const {
    return hash_t((long long)hash0 * x % md0, (long long)hash1 * x % md1);
  }

  hash_t operator - (const hash_t &x) const {
    return hash_t((hash0 + md0 - x.hash0) % md0, (hash1 + md1 - x.hash1) % md1);
  };

  hash_t operator * (const hash_t &x) const {
    return hash_t((long long)hash0 * x.hash0 % md0, (long long)hash1 * x.hash1 % md1);
  }

  long long get() {
    return (long long)hash0 * md1 + hash1;
  }
};

vector<int> kmp(vector<int> a) {
  int n = a.size();
  vector<int> fail(n);
  fail[0] = -1;
  for (int i = 1; i < n; ++i) {
    fail[i] = fail[i - 1];
    while (~fail[i] && a[fail[i] + 1] != a[i]) {
      fail[i] = fail[fail[i]];
    }
    if (a[fail[i] + 1] == a[i]) {
      ++fail[i];
    }
  }
  return fail;
}

int match(vector<int> a, vector<int> b) {
  vector<int> fail = kmp(b);
  int n = a.size(), m = b.size(), result = 0;
  for (int i = 0, j = -1; i < n; ++i) {
    while (~j && a[i] != b[j + 1]) {
      j = fail[j];
    }
    if (a[i] == b[j + 1]) {
      ++j;
    }
    if (j == m - 1) {
      ++result;
      j = fail[j];
    }
  }
  return result;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  const int m = 100;

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    --x;
    --y;
    adj[x].emplace_back(y, s[0] - 'a' + 1);
    adj[y].emplace_back(x, s[0] - 'a' + 1);
  }

  int log_n = 0;
  while (1 << log_n < n) {
    ++log_n;
  }
  vector<vector<int>> jump(m + 1, vector<int> (n, -1)), parent(log_n, vector<int> (n, -1));
  vector<hash_t> hash(n), power(n);
  vector<int> depth(n), value(n);
  power[0] = hash_t(1, 1);
  for (int i = 1; i < n; ++i) {
    power[i] = power[i - 1] * base;
  }
  
  function<void(int)> dfs = [&](int x) {
    for (int i = 1; depth[x] >> i; ++i) {
      parent[i][x] = parent[i - 1][parent[i - 1][x]];
    }
    jump[0][x] = x;
    for (int i = 1; i <= m && i <= depth[x]; ++i) {
      jump[i][x] = jump[i - 1][parent[0][x]];
    }
    for (auto e : adj[x]) {
      int y = e.first, w = e.second;
      if (y != parent[0][x]) {
        value[y] = w;
        parent[0][y] = x;
        depth[y] = depth[x] + 1;
        hash[y] = hash[x] * base + w;
        dfs(y);
      }
    }
  };

  auto go_up = [&](int x, int d) {
    for (int i = 0; depth[x] > d; ++i) {
      if (depth[x] - d >> i & 1) {
        x = parent[i][x];
      }
    }
    return x;
  };

  auto lca = [&](int x, int y) {
    if (depth[x] < depth[y]) {
      swap(x, y);
    }
    x = go_up(x, depth[y]);
    if (x == y) {
      return x;
    }
    for (int i = log_n - 1; ~i; --i) {
      if (parent[i][x] != parent[i][y]) {
        x = parent[i][x];
        y = parent[i][y];
      }
    }
    return parent[0][x];
  };

  dfs(0);
  int q;
  cin >> q;
  vector<int> answer(q);
  vector<vector<pair<int, pair<long long, int>>>> event(m + 1);

  for (int i = 0; i < q; ++i) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    --x;
    --y;
    if (x == y) {
      continue;
    }

    int l = s.length(), z = lca(x, y);
    int u = go_up(x, min(depth[x], depth[z] + l - 1));
    int v = go_up(y, min(depth[y], depth[z] + l - 1));
    vector<int> left, right;
    for (int t = u; t != z; t = parent[0][t]) {
      left.push_back(value[t]);
    }
    for (int t = v; t != z; t = parent[0][t]) {
      right.push_back(value[t]);
    }
    reverse(right.begin(), right.end());
    for (auto t : right) {
      left.push_back(t);
    }
    right.clear();
    for (auto c : s) {
      right.push_back(c - 'a' + 1);
    }
    answer[i] = match(left, right);
    
    if (x != u) {
      hash_t hash(0, 0);
      for (int t = right.size() - 1; ~t; --t) {
        hash = hash * base + right[t];
      }
      event[l].emplace_back(x, make_pair(hash.get(), i));
      event[l].emplace_back(u, make_pair(hash.get(), i + q));
    }
    if (y != v) {
      hash_t hash(0, 0);
      for (int t = 0; t < right.size(); ++t) {
        hash = hash * base + right[t];
      }
      event[l].emplace_back(y, make_pair(hash.get(), i));
      event[l].emplace_back(v, make_pair(hash.get(), i + q));
    }
  }

  auto get_hash = [&](int x, int y) {
    return (hash[x] - hash[y] * power[depth[x] - depth[y]]).get();
  };

  for (int i = 1; i <= m; ++i) {
    if (!event[i].empty()) {
      vector<vector<pair<long long, int>>> queries(n);
      for (auto e : event[i]) {
        queries[e.first].push_back(e.second);
      }
      unordered_map<long long, int> appear;

      function<void(int)> solve = [&](int x) {
        if (~jump[i][x]) {
          ++appear[get_hash(x, jump[i][x])];
        }
        for (auto e : queries[x]) {
          if (e.second < q) {
            answer[e.second] += appear[e.first];
          } else {
            answer[e.second - q] -= appear[e.first];
          }
        }
        for (auto e : adj[x]) {
          if (e.first != parent[0][x]) {
            solve(e.first);
          }
        }
        if (~jump[i][x]) {
          --appear[get_hash(x, jump[i][x])];
        }
      };

      solve(0);
    }
  }

  for (int i = 0; i < q; ++i) {
    printf("%d\n", answer[i]);
  }
  return 0;
}