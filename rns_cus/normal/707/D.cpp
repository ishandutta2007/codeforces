#include <bits/stdc++.h>
using namespace std;
#define M 10000100

int cur, n, m, Q;

struct Node {
  Node *l, *r;
  int sz[2]; bool rev;
} pool[M], *nil = pool + (cur++);

Node* root[100010];

void init() {
  nil -> l = nil, nil -> r = nil;
  nil -> sz[0] = 1; nil -> sz[1] = 0;
  nil -> rev = 0;
}

void up(Node* now) {
  for (int i = 0; i < 2; i++)
    now -> sz[i] = now -> l -> sz[i] + now -> r -> sz[i];
}

void copy(Node* now, Node* old) {
  now -> l = old -> l, now -> r = old -> r;
  now -> rev = old -> rev;
  for (int i = 0; i < 2; i++) now -> sz[i] = old -> sz[i];
}

void down(Node* now, int l = 0, int r = 0) {
  if (now -> rev) {
    Node* L = pool + (cur++); copy(L, now -> l);
    swap(L -> sz[0], L -> sz[1]); L -> rev ^= 1;

    Node* R = pool + (cur++); copy(R, now -> r);
    swap(R -> sz[0], R -> sz[1]); R -> rev ^= 1;

    now -> l = L, now -> r = R;
    now -> rev = 0;
  }
}

Node* build(int l, int r) {
  Node* now = pool + (cur++);
  if (l == r) {copy(now, nil); return now;}
  int mid = (l + r) >> 1;
  now -> l = build(l, mid);
  now -> r = build(mid + 1, r);
  up(now);
  return now;
}

Node* update(Node* old, int l, int r, int x, int bf) {
  Node* now = pool + (cur++); copy(now, old);
  if (l == r) {
    if (bf) now -> sz[0] = 0, now -> sz[1] = 1;
    else now -> sz[0] = 1, now -> sz[1] = 0;
    return now;
  }
  down(now);
  int mid = (l + r) >> 1;
  if (x <= mid) now -> l = update(now -> l, l, mid, x, bf);
  else now -> r = update(now -> r, mid + 1, r, x, bf);
  up(now);
  return now;
}

Node* invert(Node* old, int st, int en, int l, int r) {
  Node* now = pool + (cur++); copy(now, old);
  if (l <= st && en <= r) {
    swap(now -> sz[0], now -> sz[1]);
    now -> rev ^= 1;
    return now;
  }
  down(now);
  int mid = (st + en) >> 1;
  if (l <= mid) now -> l = invert(now -> l, st, mid, l, r);
  if (mid < r) now -> r = invert(now -> r, mid + 1, en, l, r);
  up(now);
  return now;
}

int main() {
  //freopen("in.txt", "r", stdin);
  init();
  scanf("%d %d %d", &n, &m, &Q);
  root[0] = build(1, n * m);
  for (int i = 1; i <= Q; i++) {
    int type, x, y;
    scanf("%d", &type);

    if (type == 1) {
      scanf("%d %d", &x, &y);
      root[i] = update(root[i - 1], 1, m * n, (x - 1) * m + y, 1);
    }
    else if (type == 2) {
      scanf("%d %d", &x, &y);
      root[i] = update(root[i - 1], 1, m * n, (x - 1) * m + y, 0);
    }
    else if (type == 3) {
      scanf("%d", &x);
      root[i] = invert(root[i - 1], 1, m * n, (x - 1) * m + 1, x * m);
    }
    else {
      scanf("%d", &x);
      root[i] = pool + (cur++);
      copy(root[i], root[x]);
    }
    printf("%d\n", root[i] -> sz[1]);
  }
}