#include<stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int opt=-1;int now=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
            int h,m;scanf("%d%d",&h,&m);
            int p=h*61+m;
            if(opt==-1||opt==p)now++;
            else
            {
                if(now>ans)ans=now;
                now=1;opt=p;
                }
            if(opt==-1)opt=p;
                }
    if(now>ans)ans=now;
    printf("%d\n",ans);
 
    return 0;
}