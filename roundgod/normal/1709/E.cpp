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
int n,k,a[MAXN];
vector<int> G[MAXN];
set<int> s[MAXN];
int val[MAXN],ans[MAXN];
void merge(int to,int v)
{
    if(s[to].size()<s[v].size())
    {
        for(auto x:s[to]) s[v].insert(x^val[to]^val[v]);
    }
    else
    {
        for(auto x:s[v]) s[to].insert(x^val[to]^val[v]);
        swap(s[to],s[v]); swap(val[to],val[v]);
    }
}
bool check(int to,int v)
{
    if(s[to].size()<s[v].size())
    {
        for(auto x:s[to])
        {
            if(s[v].count(x^val[to]^val[v])) return false;
        }
        return true;
    }
    else
    {
        for(auto x:s[v])
        {
            if(s[to].count(x^val[to]^val[v])) return false;
        }
        return true;
    }
}
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        ans[v]+=ans[to];
    }
    s[v].insert(0); val[v]=a[v];
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(!check(to,v))
        {
            ans[v]++;
            s[v].clear();
            return;
        }
        else {val[to]^=a[v]; merge(to,v);}
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans[1]);
    return 0;
}