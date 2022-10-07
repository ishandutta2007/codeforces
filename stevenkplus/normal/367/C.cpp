#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int N, M;
int ar[MAXN];

int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; ++i) {
    scanf("%d", ar + i);
    scanf("%d", ar + i);
  }

  sort(ar, ar + M);

  int num = 0;
  int val = 0;
  int nval = 0;
  int c2 = 0;

  while (nval <= N && num + 1 <= M) {
    val = nval;
    ++num;
    c2 += num;
    if ((num + 1) % 2 == 1) nval = c2 + 1;
    else nval = c2 + 1 + (num - 1) / 2;
    //printf("c2 = %d, nval = %d, nnum = %d\n", c2, nval, num + 1);
  }

  long long ans = 0;
  for(int i = 0; i < num; ++i) {
    ans += ar[M - i - 1];
  }

  cout << ans << "\n";
  return 0;
}