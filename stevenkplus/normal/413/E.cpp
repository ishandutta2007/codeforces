#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 18;
const int inf = 1 << 29;

char A[MAXN], B[MAXN];
int N, M;

struct node {
  int ar[2][2];
  node() {
    ar[0][0] = ar[1][1] = 0;
    ar[0][1] = ar[1][0] = inf;
  }
};

node operator+(node a, node b) {
  node c;
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      int ans = inf;
      for(int k = 0; k < 2; ++k) {
        int val = a.ar[i][k] + b.ar[k][j];
        if (val < ans) ans = val;
      }
      c.ar[i][j] = ans;
    }
  }
  return c;
}

node ZERO;

node SEG[MAXN * 2];

node make(int pos) {
  node c;
  c.ar[0][0] = 1;
  c.ar[1][1] = 1;
  if (A[pos] != 'X' || B[pos + 1] != 'X') {
    c.ar[1][0] = 2;
  }
  if (A[pos + 1] != 'X' || B[pos] != 'X') {
    c.ar[0][1] = 2;
  }
  if (A[pos + 1] == 'X') {
    c.ar[0][0] = c.ar[1][0] = inf;
  }
  if (B[pos + 1] == 'X') {
    c.ar[0][1] = c.ar[1][1] = inf;
  }

  return c;
}

void build(int cur = 1, int l = 0, int r = MAXN) {
  if (l + 1 == r) {
    SEG[cur] = make(l);
  } else {
    int mid = (l + r) / 2;
    build(cur*2, l, mid);
    build(cur*2+1, mid, r);
    SEG[cur] = SEG[cur*2] + SEG[cur*2+1];
  }
}


node ask(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
  int mid = (l + r) /2;
  if (left <= l && r <= right) return SEG[cur];
  else if (left >= r || l >= right) return ZERO;
  else return ask(left, right, cur*2, l, mid) + ask(left, right, cur*2+1, mid, r);
}


int main() {
  scanf("%d %d",& N, &M);
  scanf("%s", A);
  scanf("%s", B);
  build();
  for(int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;
    if (a % N > b % N) swap(a, b);
    int ans;
    if (a % N == b % N) {
      if (a != b) ans = 1;
      else ans = 0;
    } else {
      node n = ask(a % N, b % N);
      int x = a / N, y = b / N;
      ans = n.ar[x][y];
    }

    if (ans == inf) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}