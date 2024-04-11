#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,n,k,a[MAXN];
vector<int> G[MAXN];
int s[MAXN],t[MAXN],szs[MAXN],szt[MAXN],fa[MAXN];
vector<int> to[MAXN];
void dfs(int v,int p,int d)
{
    fa[v]=p;
    if(d&1)
    {
        s[v]^=1; t[v]^=1;
    }
    szs[v]=s[v]; szt[v]=t[v];
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
        szs[v]+=szs[to]; szt[v]+=szt[to];
    }
}
vector<P> ans;
bool solve(int v)
{
    if(to[v].size())
    {
        int nxt=to[v].back();
        if(s[nxt]) {solve(nxt); if(s[nxt]) return false;}
        s[v]=0; s[nxt]=1; ans.push_back(P(v,nxt));
        to[v].pop_back();
        return solve(nxt);
    }
    return true;
}
int main()
{
    scanf("%d",&tot);
    while(tot--)
    {
        ans.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear(),to[i].clear(),s[i]=0,t[i]=0;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
            s[u]^=1; s[v]^=1;
        }
        dfs(1,0,0);
        if(szs[1]!=szt[1])
        {
            puts("NO");
            continue;
        }
        bool f=true;
        for(int i=2;i<=n;i++)
        {
            if(szs[i]==szt[i]-1)
            {
                to[fa[i]].push_back(i);
            }
            else if(szt[i]==szs[i]-1)
            {
                to[i].push_back(fa[i]);
            }
            else
            {
                f=false;
                break;
            }
        }
        if(!f)
        {
            puts("NO");
            continue;
        }
        f=true;
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(s[i]) {if(!solve(i)) {f=false; break;}}
        if(!f||ans.size()!=n-1) {puts("NO"); continue;}
        puts("YES");
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}