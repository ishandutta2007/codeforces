#include <bits/stdc++.h>

using namespace std;

const int A = 26;
const int B = 321;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<vector<int>> nxt;
  vector<int> pr0;
  int m = 0;
  auto new_node = [&](int p) {
    nxt.push_back(vector<int>(A, -1));
    pr0.push_back(p);
    return m++;
  };
  int r = new_node(-1);
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    int v = r;
    for (char c : s[i]) {
      if (nxt[v][c - 'a'] == -1) {
        nxt[v][c - 'a'] = new_node(v);
      }
      v = nxt[v][c - 'a'];
    }
    pos[i] = v;
  }
  vector<int> dl0(m), dr0(m);
  vector<int> seq0;
  function<void(int)> dfs0 = [&](int v) {
    dl0[v] = seq0.size();
    seq0.push_back(v);
    for (int i = 0; i < 26; ++i) {
      if (nxt[v][i] != -1) {
        dfs0(nxt[v][i]);
      }
    }
    dr0[v] = seq0.size();
  };
  dfs0(r);
  vector<int> pr1(m, -1);
  queue<int> que;
  for (int i = 0; i < A; ++i) {
    if (nxt[r][i] == -1) {
      nxt[r][i] = r;
    } else {
      pr1[nxt[r][i]] = r;
      que.push(nxt[r][i]);
    }
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int i = 0; i < A; ++i) {
      if (nxt[v][i] == -1) {
        nxt[v][i] = nxt[pr1[v]][i];
      } else {
        pr1[nxt[v][i]] = nxt[pr1[v]][i];
        que.push(nxt[v][i]);
      }
    }
  }
  vector<vector<int>> g(m);
  for (int i = 1; i < m; ++i) {
    g[pr1[i]].push_back(i);
  }
  vector<int> dl1(m), dr1(m);
  vector<int> seq1;
  function<void(int)> dfs1 = [&](int v) {
    dl1[v] = seq1.size();
    seq1.push_back(v);
    for (int u : g[v]) {
      dfs1(u);
    }
    dr1[v] = seq1.size();
  };
  dfs1(r);
  int b = (m - 1) / B + 1;
  vector<vector<int>> cnt(m, vector<int>(b));
  ++cnt[r][dl1[r] / B];
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < b; ++j) {
      cnt[i][j] = cnt[pr0[i]][j];
    }
    ++cnt[i][dl1[i] / B];
  }
  vector<int> offset_block(b), offset_single(b);
  vector<int> single(m);
  auto modify_single = [&](int v) {
    int l = dl0[v], r = dr0[v];
    ++single[l];
    ++offset_single[l / B];
    if (r != m) {
      --single[r];
      --offset_single[r / B];
    }
  };
  auto modify = [&](int v) {
    int l = dl1[v], r = dr1[v];
    while (l < r && l % B) {
      modify_single(seq1[l++]);
    }
    while (l < r && r % B) {
      modify_single(seq1[--r]);
    }
    for (int i = l / B; i < r / B; ++i) {
      ++offset_block[i];
    }
  };
  auto query_single = [&](int p) {
    ++p;
    int res = 0;
    while (p % B) {
      res += single[--p];
    }
    for (int i = 0; i < p / B; ++i) {
      res += offset_single[i];
    }
    return res;
  };
  auto query = [&](int v) {
    long long res = 0;
    for (int i = 0; i < b; ++i) {
      res += (long long) offset_block[i] * cnt[v][i];
    }
    return res + query_single(dl0[v]);
  };
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    --l; --r; --k;
    if (l) {
      queries[--l].emplace_back(k, i + q);
    }
    queries[r].emplace_back(k, i);
  }
  vector<long long> ans(q);
  for (int i = 0; i < n; ++i) {
    modify(pos[i]);
    for (auto p : queries[i]) {
      if (p.second < q) {
        ans[p.second] += query(pos[p.first]);
      } else {
        ans[p.second - q] -= query(pos[p.first]);
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}