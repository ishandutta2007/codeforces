#include <cstdio>

typedef double ld;

const int MAXN = 10;
int ar[MAXN];
int A[MAXN], B[MAXN];


int N;

void mx(int &a, int b) {
  if (b > a) a = b;
}
void mn(int &a, int b) {
  if (b < a) a = b;
}


int ask(int a, int b, int p, int k) {
  int l = a, r = b;
  if (k == 0) mx(l, p), mn(r, p);
  else if (k == -1) mn(r, p - 1);
  else if (k == 1) mx(l, p + 1);
  if (r >= l) return r - l + 1;
  else return 0;
}

ld go(int price) {
  ld prod = 1;
  for(int i = 0; i < N; ++i) {
    prod *= ask(A[i], B[i], price, ar[i]);
    prod /= B[i] - A[i] + 1;
  }
  return prod;

}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d %d", A + i, B + i);
  }

  ld ans = 0;
  for(int p = 1; p <= 10000; ++p) {
    ld prob = 0;
    for(int i = 0; i < N; ++i) { // winner
      for(int j = 1; j < (1 << N); ++j) { // seconds
        if (j & (1 << i)) continue;
        ar[i] = 1;
        for(int k = 0; k < N; ++k) {
          if (i == k) continue;
          if (j & (1 << k)) {
            ar[k] = 0;
          } else {
            ar[k] = -1;
          }
        }

        ld g = go(p);
        prob += g;
      }
    }

    for(int i = 0; i < (1 << N); ++i) {
      int cnt = 0;
      for(int j = 0; j < N; ++j) {
        if (i & (1 << j)) {
          ++cnt;
          ar[j] = 0;
        } else {
          ar[j] = -1;
        }
      }

      if (cnt >= 2) {
        ld g = go(p);
        prob += g;
      }
    }

    ans += prob * p;
  }

  printf("%.10Lf\n", ans);
}