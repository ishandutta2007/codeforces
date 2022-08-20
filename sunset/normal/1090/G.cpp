#include <bits/stdc++.h>

using namespace std;

const int N = 256789;
const int M = 22345678;

struct node_t {
  int l, r, has, tag;
} node[M];

int n, m, total, a[N], h[N], dead[N], root[N];

int build(int l, int r) {
  int x = ++total;
  node[x].tag = -1;
  node[x].has = !l;
  if (l != r) {
    int y = l + r >> 1;
    node[x].l = build(l, y);
    node[x].r = build(y + 1, r);
  }
  return x;
}

void apply(int &x, int v) {
  int y = ++total;
  node[y] = node[x];
  x = y;
  node[x].has = node[x].tag = v;
}

void push(int &x) {
  int y = ++total;
  node[y] = node[x];
  x = y;
  if (~node[x].tag) {
    apply(node[x].l, node[x].tag);
    apply(node[x].r, node[x].tag);
    node[x].tag = -1;
  }
}

void modify(int &x, int l, int r, int ll, int rr, int v) {
  if (l == ll && r == rr) {
    apply(x, v);
  } else {
    int y = l + r >> 1;
    push(x);
    if (rr <= y) {
      modify(node[x].l, l, y, ll, rr, v);
    } else if (ll > y) {
      modify(node[x].r, y + 1, r, ll, rr, v);
    } else {
      modify(node[x].l, l, y, ll, y, v);
      modify(node[x].r, y + 1, r, y + 1, rr, v);
    }
    node[x].has = node[node[x].l].has | node[node[x].r].has;
  }
}

int query(int x, int l, int r, int p) {
  if (node[x].tag == 1) {
    return min(r, p);
  } else if (!node[x].tag || !node[x].has) {
    return -1;
  } else if (l == r) {
    return l;
  } else {
    int y = l + r >> 1;
    if (p > y) {
      int result = query(node[x].r, y + 1, r, p);
      if (~result) {
        return result;
      }
    }
    return query(node[x].l, l, y, p);
  }
}

void attack(int x, int a, int t) {
  if (h[x] <= a) {
    dead[x] = t;
    return;
  }
  a = h[x] - a;
  int p = query(root[x], 0, n - 1, a);
  if (!~p) {
    dead[x] = t;
    return;
  }
  modify(root[x], 0, n - 1, p, p, 0);
  if (p != a) {
    modify(root[x], 0, n - 1, p + 1, a, 1);
  }
  if (!node[root[x]].has) {
    dead[x] = t;
    return;
  }
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &n);
  int initial = build(0, n - 1);
  for (int i = 1; i <= n; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      ++m;
      root[m] = initial;
      dead[m] = -1;
    } else if (type == 2) {
      int x;
      scanf("%d", &x);
      ++a[x];
    } else if (type == 3) {
      int x;
      scanf("%d", &x);
      ++h[x];
    } else if (type == 4) {
      int x;
      scanf("%d", &x);
      ++m;
      if (~dead[x]) {
        dead[m] = i;
      } else {
        a[m] = a[x];
        h[m] = h[x];
        root[m] = root[x];
        dead[m] = -1;
      }
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      if (!~dead[x] && !~dead[y]) {
        attack(x, a[y], i);
        attack(y, a[x], i);
      }
    }
  }
  printf("%d\n", m);
  for (int i = 1; i <= m; ++i) {
    printf("%d%c", dead[i], i == m ? '\n' : ' ');
  }
  return 0;
}