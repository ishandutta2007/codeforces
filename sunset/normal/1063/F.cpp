#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int M = 20;
const int ALPHA = 26;

int n, dfn, root, total, p[N], dp[N], dfnl[N], dfnr[N], value[N], parent[N], tree[N << 1], ancestor[M][N], go[N][ALPHA];
vector<int> adj[N];
char s[N];

int extend(int p, int w) {
  int np = ++total;
  value[np] = value[p] + 1;
  while (p && !go[p][w]) {
    go[p][w] = np;
    p = parent[p];
  }
  if (!p) {
    parent[np] = root;
  } else {
    int q = go[p][w];
    if (value[q] == value[p] + 1) {
      parent[np] = q;
    } else {
      int nq = ++total;
      value[nq] = value[p] + 1;
      parent[nq] = parent[q];
      parent[q] = parent[np] = nq;
      memcpy(go[nq], go[q], sizeof go[nq]);
      while (p && go[p][w] == q) {
        go[p][w] = nq;
        p = parent[p];
      }
    }
  }
  return np;
}

void dfs(int x) {
  dfnl[x] = ++dfn;
  ancestor[0][x] = parent[x];
  for (int i = 1; i < M; ++i) {
    ancestor[i][x] = ancestor[i - 1][ancestor[i - 1][x]];
  }
  for (auto y : adj[x]) {
    dfs(y);
  }
  dfnr[x] = dfn;
}

int get(int x, int length) {
  x = p[x];
  for (int i = M - 1; ~i; --i) {
    if (value[ancestor[i][x]] >= length) {
      x = ancestor[i][x];
    }
  }
  return x;
}

void modify(int x, int l, int r, int p, int value) {
  tree[x] = max(tree[x], value);
  if (l != r) {
    int y = l + r >> 1, z = x + (y - l + 1 << 1);
    if (p <= y) {
      modify(x + 1, l, y, p, value);
    } else {
      modify(z, y + 1, r, p, value);
    }
  }
}

int query(int x, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return tree[x];
  } else {
    int y = l + r >> 1, z = x + (y - l + 1 << 1);
    if (qr <= y) {
      return query(x + 1, l, y, ql, qr);
    } else if (ql > y) {
      return query(z, y + 1, r, ql, qr);
    } else {
      return max(query(x + 1, l, y, ql, y), query(z, y + 1, r, y + 1, qr));
    }
  }
}

bool valid(int x) {
  if (dp[x] == 1) {
    return true;
  }
  int p = get(x, dp[x] - 1), q = get(x - 1, dp[x] - 1);
  return query(1, 1, total, dfnl[p], dfnr[p]) >= dp[x] - 1 || query(1, 1, total, dfnl[q], dfnr[q]) >= dp[x] - 1;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %s", &n, s + 1);
  reverse(s + 1, s + n + 1);
  root = total = 1;
  p[0] = root;
  for (int i = 1; i <= n; ++i) {
    p[i] = extend(p[i - 1], s[i] - 'a');
  }
  for (int i = 2; i <= total; ++i) {
    adj[parent[i]].push_back(i);
  }
  dfs(root);
  for (int i = 1, j = 0; i <= n; ++i) {
    dp[i] = dp[i - 1] + 1;
    while (!valid(i)) {
      --dp[i];
      ++j;
      modify(1, 1, total, dfnl[get(j, dp[j])], dp[j]);
    }
  }
  printf("%d\n", *max_element(dp + 1, dp + n + 1));
  return 0;
}