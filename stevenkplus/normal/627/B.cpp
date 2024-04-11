#include <cstdio>

using namespace std;

const int MAXN = 200100;
int A[MAXN], B[MAXN];

int N, K, a, b, Q;
int cnt[MAXN];

int get(int *bit, int x) {
  int sm = 0;
  while (x) {
//    printf("bit[%d] = %d\n", x, bit[x]);
    sm += bit[x];
    x -= x & -x;
  }
  return sm;
}

void inc(int *bit, int x, int val) {
  while (x < MAXN) {
    bit[x] += val;
    x += x & -x;
  }
}

void upd(int x, int val) {
  if (cnt[x] + val > a) {
    if (cnt[x] < a)
    inc(A, x, a - cnt[x]);
  } else {
    inc(A, x, val);
  }

  if (cnt[x] + val > b) {
    if (cnt[x] < b)
    inc(B, x, b - cnt[x]);
  } else {
    inc(B, x, val);
  }
  cnt[x] += val;
}

int sm(int *bit, int x, int y) {
  return get(bit, y) - get(bit, x - 1);
}

int main() {
  scanf("%d %d %d %d %d", &N, &K, &b, &a, &Q);
  for(int i = 0; i < Q; ++i) {
    int qtype;
    scanf("%d", &qtype);
    if (qtype == 1) {
      int x, val;
      scanf("%d %d", &x, &val);
      upd(x, val);
    } else { // qtype == 2
      int p;
      scanf("%d", &p);
      int ans1 = sm(A, 1, p - 1);
      int ans2 = sm(B, p + K, N);
//      printf("ans1 = %d, ans2 = %d\n", ans1, ans2);
      int ans = ans1 + ans2;
      printf("%d\n", ans);
    }
  }

  return 0;
}