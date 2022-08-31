#include<stdio.h>
using namespace std;
int main()
{
    int ans=0;
    int n;scanf("%d",&n);
    while(n--)
    {
              int a,b;scanf("%d%d",&a,&b);
              ans+=(b-a>=2);
              }
    printf("%d\n",ans);
    return 0;
}