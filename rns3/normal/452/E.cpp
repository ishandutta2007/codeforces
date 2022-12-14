#include <bits/stdc++.h>

using namespace std;

#define N 300005

const int MOD = 1000000007;

typedef long long LL;

const int NN = N * 6;

struct Node {
  int len, cnt[3];
  Node *ch[26], *fail;
  void clear() {
    len = 0, fail = 0;
    memset(ch, 0, sizeof ch);
  }
} pool[NN], *head, *last, *sz;

void init() {
  if (sz != pool) {
    for (Node* p = pool; p < sz; p ++) p -> clear();
  }
  sz = pool;
  head = last = sz ++;
}

void add(int c) {
  if (last -> ch[c]) {
    Node *p = last, *q = p -> ch[c];
    if (p -> len + 1 == q -> len) {
      last = q;
      return;
    }
  }
  Node *p = last, *np = sz ++;
  last = np, np -> len = p -> len + 1;
  for ( ; p && !p -> ch[c]; p = p -> fail) p -> ch[c] = np;
  if (p) {
    Node *q = p -> ch[c];
    if (p -> len + 1 == q -> len) np -> fail = q;
    else {
      Node *nq = sz ++; *nq = *q;
      for (int i = 0; i < 3; i ++) nq -> cnt[i] = 0;
      nq -> len = p -> len + 1;
      q -> fail = np -> fail = nq;
      for ( ; p && p -> ch[c] == q; p = p -> fail) p -> ch[c] = nq;
    }
  } else np -> fail = head;
}

LL sum[N];
int d[N];
Node *ord[NN];

void build() {
  for (int i = 0; i < N; i ++) d[i] = 0;
  for (Node* p = pool; p < sz; p ++) d[p -> len] ++;
  for (int i = 0; i < N; i ++) d[i] += d[i - 1];
  for (Node* p = pool; p < sz; p ++) ord[-- d[p -> len]] = p;
  for (int i = sz - pool - 1; i; i --) {
    Node *p = ord[i];
    for (int j = 0; j < 3; j ++) {
      p -> fail -> cnt[j] += p -> cnt[j];
    }
    LL tot = 1LL * p -> cnt[0] * p -> cnt[1] * p -> cnt[2] % MOD;
    sum[p -> fail -> len + 1] += tot;
    sum[p -> len + 1] -= tot;
  }
}

char s[N];

main() {
  init();
  int m = N;
  for (int i = 0; i < 3; i ++) {
    last = head;
    scanf("%s", s);
    int n = strlen(s);
    for (int j = 0; j < n; j ++) {
      add(s[j] - 'a');
      last -> cnt[i] ++;
    }
    if (m > n) m = n;
  }
  build();
  for (int i = 1; i <= m; i ++) {
    sum[i] += sum[i - 1];
    printf("%I64d ", (sum[i] + MOD) % MOD);
  }
}