#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str[MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];
vector<int> G[MAXN];
int match[MAXN];
bool used[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<n+m;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        cin>>str[i];
        for(int j=0;j<m;j++) if(str[i][j]=='B') f[i][j]=1;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            g[i][j]=(f[i][j]^f[i+1][j]^f[i][j+1]^f[i+1][j+1]);
            if(g[i][j]) cnt++;
        }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
            if(g[i][j]&&g[i][m-1]&&g[n-1][j])
                add_edge(i,n-1+j);
    int num=bipartite_matching();
    cnt-=num;
    if(num&1)
    {
        if(g[n-1][m-1]) cnt--; else cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}