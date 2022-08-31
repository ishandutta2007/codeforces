#include<stdio.h>
#include<cstring>
#define MAXN 210000
using namespace std;
typedef long long LL;
LL f[2][MAXN];
int n;LL data[MAXN];
int bel;
int d1,x1;
LL dfs(int d,int x)
{
           if(x>n||x<=0)return 0;
           if(f[d][x]!=-2)return f[d][x];
           f[d][x]=-1;
           if(!d)
           {
                 LL p=dfs(1,x+data[x]);
                 if(p==-1){f[d][x]=-1;return -1;}
                 f[d][x]=p+data[x];
                 }
           else
           {
               LL p=dfs(0,x-data[x]);
               if(p==-1){f[d][x]=-1;return -1;}
               f[d][x]=p+data[x];
               }
           return f[d][x];
}                            
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)scanf("%I64d",&data[i]);
    for(int i=1;i<=n;i++)for(int j=0;j<2;j++)f[j][i]=-2;
    for(int i=2;i<=n;i++)
    {
            //data[1]=i-1;
            dfs(0,i);
            dfs(1,i);
            }
    for(int i=2;i<=n;i++)
    {
            LL u=dfs(1,i);if(u!=-1)u+=i-1;
            printf("%I64d\n",u);
            }
    //printf("__%I64d\n",f[1][4]);
    return 0;
}