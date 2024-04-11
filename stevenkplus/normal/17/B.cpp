#include <cstdio>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 10100;
int N, M;

int ar[MAXN];
int main() {
 scanf("%d", &N);
 for(int i = 1; i <= N; ++i) {
  int tmp;
  scanf("%d", &tmp);
  ar[i] = inf;
 }

 scanf("%d", &M);
 for(int i = 1; i <= M; ++i) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if (c < ar[b]) {
   ar[b] = c;
  }
 }

 int sum = 0;
 int cnt = 0;
 for(int i = 1; i <= N; ++i) {
  if (ar[i] == inf) {
   ++cnt;
   if (cnt > 1) {
    sum = -1;
    break;
   }
  } else {
   sum += ar[i];
  }
 }

 printf("%d\n", sum);
 return 0;
}