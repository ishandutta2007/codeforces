#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m;
long long ans1,ans2;
struct sqe
{
  int w,x;     
} a[100005];

int cmp(sqe x, sqe y) {return x.w < y.w;}

int main()
{
 // freopen("~input.txt","r",stdin);
//  freopen("~output.txt","w",stdout);
  int i,x,top,bot,mid;  
  scanf("%d",&n);  
  for (i = 1 ;i <= n ;i ++)
    scanf("%d",&a[i].w) , a[i].x = i;
  sort(a + 1,a + 1 + n,cmp);
  scanf("%d",&m);
  while (m --)
  {
    scanf("%d",&i); 
    top = 1 , bot = n;
    while (top <= bot)
    {
      mid = (top + bot) >> 1;
      if (a[mid].w == i)
        break;
      if (a[mid].w > i)
        bot = mid - 1;         
      if (a[mid].w < i)
        top = mid + 1;  
    }   
    mid = a[mid].x;
    ans1 += mid;
    ans2 += n - mid + 1;
  }  
  printf("%I64d %I64d\n",ans1,ans2);
 // getchar();getchar();
  return 0;
}