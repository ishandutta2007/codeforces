#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 100005
int n,a[N],b[N], ans = 1 << 30;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i , x;  
  scanf("%d",&n);
  for (i = 1 ;i <= n ;i ++)
  {
    scanf("%d",&x);
    a[i] = a[i - 1], b[i] = b[i - 1];
    if (x >= 0) a[i] ++;
    if (x <= 0) b[i] ++;      
  }
  for (i = 1 ;i < n ;i ++)
    ans = min(ans , a[i] + b[n] - b[i]);  
  printf("%d",ans);
  return 0;
}