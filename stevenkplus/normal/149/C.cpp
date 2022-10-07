#include <cstdio>

using namespace std;

const int MAXN = 100100;

int ans1[MAXN];
int ans2[MAXN];
int N;

int main() {
 scanf("%d", &N);
 int x = 0, y = 0;
 int cursum = 0;
 int i;
 for(i = 1; i + 1 <= N; i += 2) {
  int a, b;
  scanf("%d %d", &a, &b);
  int diff = a - b;
  bool add = (diff > 0) == (cursum < 0);
  if (add) {
   cursum += diff;
   ans1[x++] = i;
   ans2[y++] = i + 1;
  } else {
   cursum -= diff;
   ans1[x++] = i + 1;
   ans2[y++] = i;
  }
 }
 if (i <= N) {
  int tmp;
  scanf("%d", &tmp);
  bool add = (tmp > 0) == (cursum < 0);
  if (add) {
   ans1[x++] = i;
  } else {
   ans2[y++] = i;
  }
 }

 printf("%d\n", x);
 for(int i = 0; i < x; ++i) {
  printf("%d\n", ans1[i]);
 }
 printf("%d\n", y);
 for(int i = 0; i < y; ++i) {
  printf("%d\n", ans2[i]);
 }

 return 0;
}