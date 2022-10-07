#include <cstdio>

using namespace std;

const int MAXN = 110;

int ar[MAXN];

int N, M;
void go(int wire, int pos) {
 int lft = pos - 1;
 int rgt = ar[wire] - pos;
 ar[wire] = 0;
 if (wire - 1 > 0) ar[wire - 1] += lft;
 if (wire + 1 <= N) ar[wire + 1] += rgt;
}


int main() {
 scanf("%d", &N);
 for(int i = 1; i <= N; ++i) {
  scanf("%d", ar + i);
 }

 scanf("%d", &M);
 for(int i = 0; i < M; ++i) {
  int a, b;
  scanf("%d %d", &a, &b);
  go(a, b);
 }

 for(int i = 1; i <= N; ++i) {
  printf("%d\n", ar[i]);
 }

 return 0;
}