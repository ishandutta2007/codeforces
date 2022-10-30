//A
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 1010

int a[N], x, y, ans, n, m, k;

int main(){
   scanf("%d %d %d", &n, &m, &k);
   for(int i = 0; i <= m; i ++) a[i] = k;
   for(int i = 0; i < n; i ++){
      scanf("%d %d", &x, &y);
      if(a[x] > y) a[x] = y;
   }
   for(int i = 1; i <= m; i ++) ans += a[i];
   printf("%d\n", min(ans, k));
}