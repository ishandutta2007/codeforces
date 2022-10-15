#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> G[MAXN];
int sg[MAXN],fa[MAXN];
bool fused[MAXN];
void dfs(int v,int p)
{
    fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sg[v]^=(sg[to]+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    int tmp=0;
    memset(fused,false,sizeof(fused));
    fused[1]=true;
    int val=sg[1];
    if(val) printf("1"); else printf("2");
    for(int i=2;i<=n;i++)
    {
        if(fused[i])
        {
            if(val^tmp) printf("1"); else printf("2");
            continue;
        }
        vector<int> vec; 
        int now=i;
        while(!fused[now])
        {
            vec.push_back(now); fused[now]=true;
            now=fa[now];
        }
        tmp^=((int)vec.size()&1);
        int topmost=vec.back();
        val^=(sg[topmost]+1);
        for(auto x:vec)
            for(auto to:G[x])
                if(!fused[to]) val^=(sg[to]+1);
        if(val^tmp) printf("1"); else printf("2");
    }
    return 0;
}