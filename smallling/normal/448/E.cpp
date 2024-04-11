#include<stdio.h>

using namespace std;

long long a[8000];
int Max,now,tot,b[8000][8000];
long long n,m;

void dfs(int x,int deep)
{
    if(!Max)return;
    if(deep==m||x==1)
    {
        Max--;
        printf("%I64d ",a[x]);
        return;
    }
    for(int i=1;i<=*b[x]&&Max;i++)dfs(b[x][i],deep+1);
}

int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(int i=1;1ll*i*i<=n;i++)
        if(n%i==0)a[++tot]=i,now=i;
    for(;now;now--)
        if(1ll*now*now!=n)
            if(n%now==0)a[++tot]=n/now;
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=i;j++)
            if(a[i]%a[j]==0)b[i][++*b[i]]=j;
    Max=100000;
    dfs(tot,0);
}