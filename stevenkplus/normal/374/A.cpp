#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int inf = 1 << 29;

int go(int a, int b, int c) {
  int x = abs(a-b);
  if(x % c == 0) return x/ c;
  else return inf;
}

int N, M, I, J, A, B;

int main() {
  scanf("%d %d %d %d %d %d", &N, &M, &I, &J, &A, &B);

  int a = go(N, I, A), b = go(1, I, A);
  int c = go(M, J, B), d = go(1, J, B);

  if (I - A < 1 && I + A > N) {
    if ((I == 1 || I == N)&& (J == M || J == 1)) printf("0\n");
    else printf("Poor Inna and pony!\n");
    return 0;
  }

  if (J - B < 1 && J + B > M) {
    if ((I == 1 || I == N)&& (J == M || J == 1)) printf("0\n");
    else printf("Poor Inna and pony!\n");
    return 0;

  }

  int ans = inf;
  if (a % 2 == c % 2) {
    ans = min(ans, max(a,c));
  }
  if (a % 2 == d % 2) {
    ans = min(ans, max(a, d));
  }
  if (b % 2 == c % 2) {
    ans = min(ans, max(b, c));
  }
  if (b % 2 == d % 2) {
    ans = min(ans, max(b, d));
  }

  if (ans < inf) printf("%d\n", ans);
  else printf("Poor Inna and pony!\n");
  return 0;
}