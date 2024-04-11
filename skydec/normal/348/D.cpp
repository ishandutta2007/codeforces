#include<stdio.h>
#include<cstring>
#define jsb 1000000007
#define MAXN 3005
using namespace std;
int f[MAXN][MAXN];
char str[MAXN][MAXN];
int n,m;
int count(int stx,int sty,int edx,int edy)
{
    memset(f,0,sizeof f);
    f[stx][sty]=1;if(str[stx][sty]=='#')return 0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(str[i][j]=='.')
    f[i][j]=(f[i][j]+(f[i-1][j]+f[i][j-1])%jsb)%jsb;
    return f[edx][edy];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
    int ans=0;
    int a,b,c,d;
    a=count(1,2,n-1,m);
    b=count(1,2,n,m-1);
    c=count(2,1,n,m-1);
    d=count(2,1,n-1,m);
    ans=a*1ll*c%jsb;
    ans=(ans-(b*1ll*d)%jsb)%jsb;
    if(ans<0)ans+=jsb;
    printf("%d\n",ans);
    return 0;
}