#include <cstdio>

const int MAXN = 5010;
int ar[MAXN];
double P[MAXN];
double SP[MAXN];

int N;
int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%d", ar + i);
  }

  double pp = 2. / (N * (N - 1));
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (ar[i] <= ar[j]) continue;
      P[ar[i] - ar[j]] += pp;
    }
  }

  for(int i = MAXN - 2; i >= 0; --i) {
    SP[i] = P[i] + SP[i + 1];
  }

  double ans = 0;
  for(int i = 0; i < MAXN; ++i) {
    for(int j = 0; i + j < MAXN; ++j) {
      int k = i + j + 1; // strictly higher
      ans += P[i] * P[j] * SP[k];
    }
  }

  printf("%.10lf\n", ans);
}