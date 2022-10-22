#include <bits/stdc++.h>
using int64 = long long;
const int N = 1500005;
const int Q = 998244353;
int n, m;

inline int RAND() {
  return (rand() << 15 ^ rand());
}

int I[N], P[N], inv[N];
void InitCombination(int n) {
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1LL * (Q - Q / i) * inv[Q % i] % Q;
  }
  P[0] = I[0] = 1;
  for (int i = 1; i <= n; ++i) {
    P[i] = 1LL * P[i - 1] * i % Q;
    I[i] = 1LL * I[i - 1] * inv[i] % Q;
  }
}
int Combination(int a, int b) {
  if (a < 0 || b < 0 || b > a) {
    return 0;
  }
  return 1LL * P[a] * I[b] % Q * I[a - b] % Q;
}
struct Treap {
  int nodecnt;
  int L[N], R[N], cnt[N], sum[N];
  int key[N], size[N];
  bool hey(int A, int B) {
    return RAND() % (cnt[A] + cnt[B]) < cnt[A];
  }
  int newnode(int val, int s) {
    // printf("++ %d %d\n", val, s);
    ++nodecnt, L[nodecnt] = R[nodecnt] = 0;
    cnt[nodecnt] = 1, key[nodecnt] = val;
    size[nodecnt] = s, sum[nodecnt] = s;
    return nodecnt;
  }
  void pushup(int x) {
    cnt[x] = 1;
    sum[x] = size[x];
    if (L[x])
      cnt[x] += cnt[L[x]], sum[x] += sum[L[x]];
    if (R[x])
      cnt[x] += cnt[R[x]], sum[x] += sum[R[x]];
  }
  void merge(int& p, int x, int y) {
    if (!x || !y)
      p = x | y;
    else if (hey(x, y))  // key[x] < key[y]
      merge(R[x], R[x], y), pushup(p = x);
    else
      merge(L[y], x, L[y]), pushup(p = y);
  }
  void split_cnt(int p, int& x, int& y, int size) {
    if (!size) {
      x = 0, y = p;
      return;
    }
    if (cnt[L[p]] >= size)
      y = p, split_cnt(L[p], x, L[y], size), pushup(y);
    else
      x = p, split_cnt(R[p], R[x], y, size - cnt[L[p]] - 1), pushup(x);
  }
  void split(int p, int& x, int& y, int s) {
    if (p == 0 || !s) {
      x = 0, y = p;
      return;
    }
    if (sum[L[p]] >= s) {
      y = p;
      split(L[p], x, L[y], s);
      pushup(y);
    } else {
      x = p;
      split(R[p], R[x], y, s - sum[L[p]] - size[p]);
      pushup(x);
    }
  }
  void real_split(int p, int& x, int& y, int s) {
    split(p, x, y, s);
    // printf("~~ %d\n", s);
    // printf("%d : %d\n", x, sum[x]);
    // printf("%d : %d\n", y, sum[y]);
    if (sum[x] > s) {
      int last = 0;
      split_cnt(x, x, last, cnt[x] - 1);
      int ls = s - sum[x];
      int rs = sum[last] - ls;
      // printf("%d %d\n", ls, rs);
      int val = key[last];
      merge(x, x, newnode(val, ls - 1));
      merge(x, x, newnode(-2, 1));
      merge(y, newnode(val + ls / 2, rs), y);
    }
  }
  void visit(int x, int& c) {
    if (L[x])
      visit(L[x], c);
    // printf("%d %d | ", key[x], size[x]);
    if (key[x] == -2) {
      ++c;
    }
    if (key[x] > 0) {
      c += size[x] / 2;
    }
    if (R[x])
      visit(R[x], c);
  }
} T;

int inverse(int x) {
  return x == 1 ? 1 : 1LL * (Q - Q / x) * inverse(Q % x) % Q;
}

int a[N], b[N];

void work() {
  T.nodecnt = 0;
  scanf("%d%d", &n, &m);
  // n = 200000, m = n - 1;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  a[m] = n + 1;
  int root = T.newnode(1, 2 * (a[0] - 1) - 1);
  for (int i = 0; i < m; ++i) {
    int x = a[i], k = b[i];

    if (k == 1) {
      int na = T.newnode(-1, 1);
      int nb = T.newnode(x, 1);
      T.merge(root, na, root);
      T.merge(root, nb, root);
    } else {
      int l, r, _;
      T.real_split(root, l, r, 2 * k - 2);
      T.real_split(l, l, _, 2 * k - 3);
      int mid = T.newnode(x, 1);
      T.merge(mid, T.newnode(-2, 1), mid);
      T.merge(mid, mid, T.newnode(-1, 1));
      T.merge(root, l, mid);
      T.merge(root, root, r);
    }
    // int xx = 0;
    // T.visit(root, xx);
    // puts("");
    if (x + 1 < a[i + 1]) {
      int sz = a[i + 1] - x - 1;
      T.merge(root, root, T.newnode(-2, 1));
      T.merge(root, root, T.newnode(x + 1, 2 * sz - 1));
    }
  }

  m = 0;
  T.visit(root, m);

  printf("%d\n", Combination(n + m, m));
}

int main() {
  InitCombination(N - 1);
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}