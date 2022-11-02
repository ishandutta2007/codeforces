#include <bits/stdc++.h>

const int max_N = (int)2e5 + 21;
const int sigma = 26;

char s[max_N], t[max_N];

int n, q;

namespace SAM {
int tot, rt, last;

int len[max_N], par[max_N], go[max_N][sigma];

int new_node(int L) {
  int x = ++tot;
  memset(go[x], 0, sizeof go[x]);
  par[x] = 0;
  len[x] = L;
  return x;
}

void extend(int c) {
  int p = last;
  int np = last = new_node(len[p] + 1);
  par[np] = rt;
  for (; p && !go[p][c]; p = par[p]) {
    go[p][c] = np;
  }
  if (p) {
    int q = par[np] = go[p][c];
    if (len[q] != len[p] + 1) {
      int nq = ++tot;
      par[nq] = par[q];
      len[nq] = len[p] + 1;
      memcpy(go[nq], go[q], sizeof go[q]);
      par[q] = par[np] = nq;
      for (; p && go[p][c] == q; p = par[p]) {
        go[p][c] = nq;
      }
    }
  }
}

int cnt[max_N], Q[max_N];

void sort(int max_L) {
  for (int i = 0; i < max_L; ++i) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= SAM::tot; ++i) {
    ++cnt[len[i]];
  }
  for (int i = 1; i < max_L; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = SAM::tot; i; --i) {
    Q[cnt[len[i]]--] = i;
  }
}

void init() {
  tot = 0;
  last = rt = new_node(0);
}
}

namespace SegmentTree {
const int max_N = ::max_N * 30;

#define mid ((l + r) >> 1)
#define lch ls[x], l, mid
#define rch rs[x], mid + 1, r

int tot, sum[max_N], ls[max_N], rs[max_N], rt[max_N];

int new_node(int pos) {
  int l = 1, r = n;
  int x = ++tot;
  sum[x] = 1;
  int y = x;
  while (l < r) {
    if (pos <= mid) {
      ls[x] = ++tot;
      x = ls[x];
      r = mid;
    } else {
      rs[x] = ++tot;
      x = rs[x];
      l = mid + 1;
    }
    sum[x] = 1;
  }
  return y;
}

int merge(int x, int y) {
  if (!x || !y) {
    return x + y;
  }
  int z = ++tot;
  sum[z] = sum[x] + sum[y];
  ls[z] = merge(ls[x], ls[y]);
  rs[z] = merge(rs[x], rs[y]);
  return z;
}

int query(int ql, int qr, int x, int l = 1, int r = n) {
  if (!x || ql > qr) {
    return 0;
  }
  if (ql <= l && r <= qr) {
    return sum[x];
  } else {
    int ret = 0;
    if (ql <= mid) {
      ret += query(ql, qr, lch);
    }
    if (qr > mid) {
      ret += query(ql, qr, rch);
    }
    return ret;
  }
}
}

int right[max_N], sl[max_N], sr[max_N];

std::vector<int> vec[max_N];

void debug_dfs(int u) {
  for (const int& v : vec[u]) {
    printf("%d-", u);
    for (int i = sl[v]; i < sr[v]; ++i) {
      putchar(s[i - 1]);
    }
    printf("->%d\n", v);
    debug_dfs(v);
  }
}

void init() {
  SAM::init();
  for (int i = n; i; --i) {
    SAM::extend(s[i - 1] - 'a');
  }
  int p = SAM::rt;
  for (int i = n; i; --i) {
    p = SAM::go[p][s[i - 1] - 'a'];
    SegmentTree::rt[p] = SegmentTree::new_node(i);
    right[p] = i;
  }
  SAM::sort(n + 1);
  for (int i = SAM::tot; i > 1; --i) {
    int u = SAM::Q[i], v = SAM::par[u];
    sl[u] = right[u] + SAM::len[v];
    sr[u] = sl[u] + SAM::len[u] - SAM::len[v];
    vec[v].push_back(u);
    right[v] = std::max(right[u], right[v]);
    SegmentTree::rt[v] = SegmentTree::merge(SegmentTree::rt[u], SegmentTree::rt[v]);
  }
  for (int i = 1; i <= SAM::tot; ++i) {
    std::sort(vec[i].begin(), vec[i].end(), [&](int x, int y) { return s[sl[x] - 1] < s[sl[y] - 1]; });
  }
  // debug_dfs(SAM::rt);
}

void query(int l, int r) {
  int m = strlen(t);
  int u = SAM::rt, len = 0;
  int ans1 = -1, ans2 = 0;
  for (int i = 0; i <= m; ++i) {
    if (sl[u] + len == sr[u]) {
      len = 0;
      for (const int& v : vec[u]) {
        if (s[sl[v] - 1] < t[i]) {
          continue;
        }
        if (s[sl[v] - 1] == t[i]) {
          u = v;
          len = 1;
        } else {
          if (SegmentTree::query(l, r - i, SegmentTree::rt[v])) {
            if (ans1 == -1 || ans2 < i + 1) {
              ans1 = sl[v] - i;
              ans2 = i + 1;
            }
          }
        }
      }
      if (!len) {
        break;
      }
    } else {
      ++len;
      if (s[sl[u] + len - 2] < t[i]) {
        break;
      }
      if (s[sl[u] + len - 2] > t[i]) {
        if (SegmentTree::query(l, r - i, SegmentTree::rt[u])) {
          if (ans1 == -1 || ans2 < i + 1) {
            ans1 = sl[u] + len - i - 1;
            ans2 = i + 1;
          }
        }
        break;
      }
    }
  }
  if (ans1 == -1) {
    puts("-1");
  } else {
    char tmp = s[ans1 + ans2 - 1];
    s[ans1 + ans2 - 1] = '\0';
    puts(s + ans1 - 1);
    s[ans1 + ans2 - 1] = tmp;
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  init();
  scanf("%d", &q);
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d%s", &l, &r, t);
    query(l, r);
  }
}