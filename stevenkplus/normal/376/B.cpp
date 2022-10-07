#include <cstdio>
#include <algorithm>

using namespace std;

int abs(int x) {
  if (x > 0) return x;
  else return -x;
}

const int MAXN = 100100;
int ar[MAXN];
int N, P;

int main() {
  scanf("%d %d", &N, &P);
  for(int i = 0; i < P; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    ar[a] += c;
    ar[b] -= c;
  }

  int sum = 0;
  for(int i = 1; i <= N; ++i) {
    sum += abs(ar[i]);
  }

  printf("%d\n", sum / 2);
  return 0;
}