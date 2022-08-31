#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
int rxd[MAXN];
int t[MAXN];
int n;
int main()
{
    scanf("%d",&n);int ans=0;
    for(int i=1;i<=n;i++)
    {
            int v;scanf("%d",&v);
            t[0]=0;
            for(int i=2;i*i<=v;i++)
            if(v%i==0)
            {
                      t[++t[0]]=i;
                      while(v%i==0)v/=i;
                      }
            if(v!=1)t[++t[0]]=v;
            int reu=0;
            for(int i=1;i<=t[0];i++)if(reu<rxd[t[i]])reu=rxd[t[i]];
            reu++;
            if(reu>ans)ans=reu;
            for(int i=1;i<=t[0];i++)
            if(reu>rxd[t[i]])rxd[t[i]]=reu;
            }
    printf("%d\n",ans);
    return 0;
}