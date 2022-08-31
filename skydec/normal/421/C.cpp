#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
long front[MAXN];long x[MAXN];long now;long p[MAXN];long n,m;long after[MAXN];bool ans[MAXN]={false};
bool up[MAXN]={false};
int main()
{
    now=0;memset(ans,true,sizeof ans);
    scanf("%ld%ld",&n,&m);
    for(long i=1;i<=m;i++)
    {
             char ps[3];scanf("%s",ps+1);scanf("%ld",&x[i]);if(ps[1]=='+')p[i]=1;else p[i]=0;
             if(ps[1]=='+')up[x[i]]=true;
             else
             {
                 if(!up[x[i]])now++;
                 }
             }
    front[0]=0;
    for(long i=1;i<=m;i++)
    if(p[i]==0)front[i]=x[i];else front[i]=front[i-1];
    after[m+1]=0;
    for(long i=m;i>=1;i--)
    if(p[i]==1)after[i]=x[i];else after[i]=after[i+1];
    for(long i=1;i<=m;i++)
    if(p[i]==1)
    {
               if(now>0)ans[x[i]]=false;
               if(front[i]!=0&&front[i]!=x[i])ans[x[i]]=false;
               now++;
               }
    else
    {
               now--;
               if(now>0)ans[x[i]]=false;
               if(after[i]!=0&&after[i]!=x[i])ans[x[i]]=false;
               }
    long reu=0;
    for(long i=1;i<=n;i++)reu+=ans[i];
    printf("%ld\n",reu);
    for(long i=1;i<=n;i++)if(ans[i])printf("%ld ",i);
    return 0;
}