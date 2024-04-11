#include<stdio.h>
#define jsb 1000000007
#define MAXN 305
using namespace std;
bool tu[305][305];long long pri[305];int d[305];
int n,m,t;int bg[1100000];
int top[110000];
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)scanf("%I64d",&pri[i]);
    for(int i=1;i<=m;i++)
    {
            int b,c;scanf("%d%d",&b,&c);
            tu[b][c]=1;d[c]++;
            }
    for(int kk=1;kk<=n;kk++)
    {
            int now=0;
            for(int i=1;i<=n;i++)if(d[i]==0)now=i;
            if(!now)
            {
                    printf("0\n");
                    return 0;
                    }
            d[now]=-1;
            for(int i=1;i<=n;i++)if(tu[now][i])d[i]--;
            top[++top[0]]=now;
            }
    for(int i=1;i<=top[0];i++)
    {
            int x=top[i];
            for(int j=1;j<=n;j++)
            {
                    if(tu[x][j])pri[j]+=pri[x],t-=pri[x];
                    if(t<0){printf("0\n");return 0;}
                    }
            }                                    
    //printf("%d\n",t);
    if(t<0){printf("0\n");return 0;}
    bg[0]=1;
    for(int i=1;i<=n;i++)
    for(long long j=pri[i];j<=t;j++)
    bg[j]=(bg[j]+bg[j-pri[i]])%jsb;
    printf("%d\n",t>=0?bg[t]:0);
    return 0;
}