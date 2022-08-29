#include<stdio.h>
#define MAXN 110000
using namespace std;
int g[MAXN];int n;int q[MAXN];int tot=0;
void dfs(int x)
{
     g[x]=1;
     if(!g[x*2%n]) dfs(x*2%n);
     if(!g[(x*2+1)%n])dfs((x*2+1)%n);
     q[++tot]=x;
}
int main()
{
    scanf("%d",&n);
    if(n&1){printf("-1\n");return 0;}
    dfs(0);
    printf("0 ");while(tot--)printf("%d ",q[tot]);
    return 0;
}