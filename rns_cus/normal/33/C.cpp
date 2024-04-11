#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 100010
int n, a[N], b[N], c[N], ans, tot;

int main(){
   scanf("%d", &n);
   for(int i = 1; i <= n; i ++){ scanf("%d", a + i); ans += a[i]; }
   b[0] = c[0] = 0;
   for(int i = 1; i <= n; i ++){ b[i] = b[i-1] - a[i]; c[i] = c[i-1] - a[n+1-i]; }
   for(int i = 1; i <= n; i ++){ b[i] = max(b[i-1], b[i]); c[i] = max(c[i-1], c[i]); }
   for(int i = 0; i <= n; i ++){ tot = max(tot, b[i] + c[n-i]); }
   printf("%d\n", ans + 2 * tot);
}