#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,m,tot,n1,n2,n3;
int color[MAXN],lab[MAXN];
vector<P> vec;
vector<int> save[MAXN][2];
int dp[MAXN][MAXN];
bool dfs(int v,int c)
{
    color[v]=c;
    if(c>0) save[tot][0].push_back(v); else save[tot][1].push_back(v);
    for(auto to:G[v])
    {
        if(color[to]==c) return false;
        if(!color[to]&&!dfs(to,-c)) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&n3);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    tot=0;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            ++tot;
            if(!dfs(i,1)) {puts("NO"); return 0;}
            vec.push_back(P((int)save[tot][0].size(),(int)save[tot][1].size()));
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<tot;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j]==-1) continue;
            if(vec[i].F==0||vec[i].S==0) dp[i+1][j]=0;
            if(j+vec[i].F<=n) dp[i+1][j+vec[i].F]=1;
            if(j+vec[i].S<=n) dp[i+1][j+vec[i].S]=2;
        }
    }
    if(dp[tot][n2]==-1) {puts("NO"); return 0;}
    puts("YES");
    int x=tot,y=n2;
    while(x>0)
    {
        if(dp[x][y]==0) x--;
        else if(dp[x][y]==1)
        {
            for(auto z:save[x][0]) lab[z]=2;
            x--; y-=vec[x].F;
        }
        else if(dp[x][y]==2)
        {
            for(auto z:save[x][1]) lab[z]=2;
            x--; y-=vec[x].S;
        }
        else assert(0);
    }
    for(int i=1;i<=n;i++)
    {
        if(lab[i]==0)
        {
            if(n1) {lab[i]=1; n1--;}
            else lab[i]=3;
        }
    }
    for(int i=1;i<=n;i++) printf("%d",lab[i]);
    return 0;
}