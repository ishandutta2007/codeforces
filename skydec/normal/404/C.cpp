#include<stdio.h>
#include<cstring>
#include<vector>
#define pb push_back
#define del pop_back
#define MAXN 210000
using namespace std;
int n,k;
int d[MAXN];
vector<int> vi[MAXN];
int rest[MAXN];
int x[MAXN],y[MAXN];int tot=0;
void dfs(int now,int dep)
{
     while(rest[now])
     {
                     if(!vi[dep+1].size())return;
                     rest[now]--;
                     x[++tot]=now;y[tot]=vi[dep+1][vi[dep+1].size()-1];
                     vi[dep+1].del();
                     rest[y[tot]]--;
                     dfs(y[tot],dep+1);
                     }
}    
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)rest[i]=k;
    for(int i=1;i<=n;i++)
    {
            int u;scanf("%d",&u);
            vi[u].pb(i);
            }
    if(vi[0].size()!=1)
    {
                       printf("-1\n");
                       return 0;
                       }
    dfs(vi[0][0],0);
    for(int i=1;i<=n;i++)if(vi[i].size()){printf("-1\n");return 0;}
    printf("%d\n",n-1);
    for(int i=1;i<=n-1;i++)printf("%d %d\n",x[i],y[i]);
    return 0;
}