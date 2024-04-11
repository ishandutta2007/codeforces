#include <cstdio>
#include <cstring>

#define cl (cur*2)
#define cr (cur*2+1)
#define mid ((l+r)/2)

struct node {
  int ar[60]; // times for each start-second
  node operator+(const node& rhs) {
    node ret;
    for(int i = 0; i < 60; ++i) {
      int tm = (i + this->ar[i]) % 60;
      ret.ar[i] = this->ar[i] + rhs.ar[tm];
    }
    return ret;
  }

  node() {
    memset(ar, 0, sizeof(ar));
  }

} zero;

const int MAXN = 1 << 17;

node SEG[MAXN * 2];

int ar[MAXN];

void upd(int x) {
  int cur = MAXN + x;
  node &n = SEG[cur];
  for(int t = 0; t < 60; ++t) {
    if (t % ar[x] == 0) {
      n.ar[t] = 2;
    } else {
      n.ar[t] = 1;
    }
  }

  cur /= 2;
  while (cur) {
    SEG[cur] = SEG[cl] + SEG[cr];
    cur /= 2;
  }
}

node ask(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
  if (left <= l && r <= right) {
    return SEG[cur];
  } else if (left >= r || l >= right) {
    return zero;
  } else {
    return ask(left, right, cl, l, mid) + ask(left, right, cr, mid, r);
  }
}

int N, Q;

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    scanf("%d", ar + i);
    upd(i);
  }

  scanf("%d", &Q);
  for(int q = 0; q < Q; ++q) {
    char qtype;
    int x, y;
    scanf(" %c", &qtype);
    if (qtype == 'A') {
      scanf("%d %d", &x, &y);
      node n = ask(x, y);
      int ans = n.ar[0];
      printf("%d\n", ans);
    } else {
      scanf("%d", &x);
      scanf("%d", ar + x);
      upd(x);
    }
  }
  return 0;
}