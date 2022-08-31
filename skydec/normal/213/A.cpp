#include<stdio.h>
#include<cstring>
#include<vector>
#define pb push_back 
#define MAXN 205
using namespace std;
bool vis[MAXN];
vector<int> need[MAXN];int ans;
int n;int pos[MAXN];int biu=0;
bool good(int x)
{
     for(int i=0;i<need[x].size();i++)
     if(!vis[need[x][i]])return 0;
     return 1;
}
void work(int now,int cost)
{
     for(;;){
     bool find=1;
     for(int i=1;i<=n;i++)
     if((!vis[i])&&(pos[i]==now))
     {
                                 if(!good(i))continue;
                                 vis[i]=1;biu++;find=0;cost++;
                                 }
     if(find)break;
                                 }
     if(biu==n){if(cost<ans)ans=cost;return;}
     work(now%3+1,cost+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            need[i].clear();
            scanf("%d",&pos[i]);
            }
    for(int i=1;i<=n;i++)
    {
            int k;scanf("%d",&k);
            for(int j=1;j<=k;j++)
            {
                    int u;scanf("%d",&u);
                    need[i].pb(u);
                    }
                    }
    ans=2100000000;
    work(1,0);
    memset(vis,0,sizeof vis);biu=0;
    work(2,0);
    memset(vis,0,sizeof vis);biu=0;
    work(3,0);
    printf("%d\n",ans);
    return 0;
}