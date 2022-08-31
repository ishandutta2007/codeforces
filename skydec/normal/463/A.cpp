#include<stdio.h>
using namespace std;
int n,s;
int ans=-1;
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
            int x,y;scanf("%d%d",&x,&y);
            if(x*100+y<=s*100)
            if(!y){if(ans<0)ans=0;}else
            if(100-y>ans)ans=100-y;
            }
    printf("%d\n",ans);
    return 0;
}