#include<stdio.h>
#include<cstring>
#define MAXN 510000
using namespace std;
char str[MAXN];
int ans=0;
int n,k;
int main()
{
    int n,k;scanf("%d%d",&n,&k);
    if(k>2)
    {
           scanf("%s",str+1);
           for(int i=2;i<=n;i++)
           if(str[i]==str[i-1])
           {
                               ans++;
             for(int p=1;p<=k;p++)
             if(p+'A'-1!=str[i-1]&&str[i+1]!=p+'A'-1)
             {
               str[i]=p+'A'-1;
               break;
               }
               }
           printf("%d\n",ans);
           printf("%s",str+1);
           }
    else
    {
        scanf("%s",str+1);int ans1=0;int ans2=0;
        for(int i=1;i<=n;i++)
        if(str[i]!='A'+(i&1))ans1++;
        else ans2++;
        if(ans1<ans2)
        {
                     printf("%d\n",ans1);
                     for(int i=1;i<=n;i++)
                     printf("%c",'A'+(i&1));
                     }
        else
        {
                     printf("%d\n",ans2);
                     for(int i=1;i<=n;i++)
                     printf("%c",'A'+(1-(i&1)));
                     }
                     }
    return 0;
}