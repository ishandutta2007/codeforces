#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,sz[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p)
{
    int res=1;
    for(int i=0;i<G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v);
        res+=sz[G[v][i]];
    }
    sz[v]=res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    if(n&1) {puts("-1"); return 0;}
    dfs(1,-1);
    int cnt=0;
    for(int i=1;i<=n;i++) if(!(sz[i]&1)) cnt++;
    printf("%d\n",cnt-1);
    return 0;
}