#include<stdio.h>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(k<n/2)
    {
             printf("-1\n");
             return 0;
             }
    if(n==1)
    {
          if(!k)printf("1");
          else printf("-1");
          return 0;
          }  
    int x=k-(n-2)/2;
    printf("%d %d ",x,2*x);
    for(int i=1;i<=(n-2)/2;i++)
    printf("%d %d ",2*x+2*i-1,2*x+2*i);
    if(n&1)printf("%d\n",2*x+n-2);
    return 0;
}