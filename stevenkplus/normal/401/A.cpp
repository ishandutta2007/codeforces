#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int N, M;
int ar[MAXN];

int x;
int main() {
  scanf("%d %d", &N, &x);
  int sum = 0;
  for(int i = 0; i<  N; ++i) {
    scanf("%d", ar + i);
    sum += ar[i];
  }
  if (sum < 0) sum = -sum;
  int ans = (sum + x - 1) / x;
  printf("%d\n", ans);
}