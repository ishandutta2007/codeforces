#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int M = 10000005;

struct node_t {
  int l, r;
} node[M];

int n, m, q, l, r, last, nodes, total, now[N], need[N], root[N], value[N], parent[N], go[N][26];
vector<int> adj[N];
char s[N], t[N];

void extend(int w) {
  int p = last, np = ++total;
  value[np] = value[p] + 1;
  while (p && !go[p][w]) {
    go[p][w] = np;
    p = parent[p];
  }
  if (!p) {
    parent[np] = 1;
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
  last = np;
}

int build(int l, int r, int p) {
  int x = ++nodes;
  if (l != r) {
    int mid = l + r >> 1;
    if (p <= mid) {
      node[x].l = build(l, mid, p);
    } else {
      node[x].r = build(mid + 1, r, p);
    }
  }
  return x;
}

int merge(int x, int y) {
  if (!x && !y) {
    return 0;
  }
  int p = ++nodes;
  if (!x || !y) {
    node[p] = x ? node[x] : node[y];
  } else {
    node[p].l = merge(node[x].l, node[y].l);
    node[p].r = merge(node[x].r, node[y].r);
  }
  return p;
}

void dfs(int x) {
  for (auto y : adj[x]) {
    dfs(y);
    root[x] = merge(root[x], root[y]);
  }
}

bool check(int x, int l, int r, int ql, int qr) {
  if (!x) {
    return false;
  }
  if (l == ql && r == qr) {
    return true;
  }
  int mid = l + r >> 1;
  if (qr <= mid) {
    return check(node[x].l, l, mid, ql, qr);
  } else if (ql > mid) {
    return check(node[x].r, mid + 1, r, ql, qr);
  } else {
    return check(node[x].l, l, mid, ql, mid) || check(node[x].r, mid + 1, r, mid + 1, qr);
  }
}

bool solve(int x, int p) {
  for (int i = max(need[x], 0); i < 26; ++i) {
    if (x <= r - l + 1 && check(root[go[p][i]], 1, n, l + x - 1, r)) {
      now[x] = i;
      if (i > need[x]) {
        for (int j = 1; j <= x; ++j) {
          putchar(now[j] + 'a');
        }
        putchar(10);
        return true;
      } else if (solve(x + 1, go[p][i])) {
        return true;
      }
    }
  }
  return false;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%s", s + 1);
  n = strlen(s + 1);
  last = total = 1;
  for (int i = 1; i <= n; ++i) {
    extend(s[i] - 'a');
    root[last] = build(1, n, i);
  }
  for (int i = 2; i <= total; ++i) {
    adj[parent[i]].push_back(i);
  }
  dfs(1);
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %s", &l, &r, t + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= m; ++i) {
      need[i] = t[i] - 'a';
    }
    need[m + 1] = -1;
    if (!solve(1, 1)) {
      puts("-1");
    }
  }
  return 0;
}