#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

double prb[MAXN];

int N;

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%lf", prb + i);
  }

  sort(prb, prb + N);

  double a = 1, b = 0;
  for(int i = N - 1; i >= 0; --i) {
    double p = prb[i];
    if (a > b) {
      b = b * (1 - p) + a * p;
      a = a * (1 - p);
    }
  }

  printf("%.10lf\n", b);
  return 0;}