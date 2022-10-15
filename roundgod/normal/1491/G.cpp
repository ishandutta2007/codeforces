#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],invp[MAXN];
bool vis[MAXN];
vector<P> ans;
vector<vector<int> > cycles;
vector<int> singletons;
void go(int u,int v)
{
    ans.push_back(P(u,v));
    swap(invp[p[u]],invp[p[v]]);
    swap(p[u],p[v]);
}
bool cmp(vector<int> &a,vector<int> &b)
{
    return a.size()>b.size();
}
void solve_cycle(int x,int y)
{
    
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) invp[p[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vector<int> tmp;
        int now=i;
        while(!vis[i])
        {
            tmp.push_back(i);
            vis[i]=true;
            i=p[i];
        }
        if(tmp.size()==1) singletons.push_back(i);
        else cycles.push_back(tmp);
    }
    sort(cycles.begin(),cycles.end(),cmp);
    while(cycles.size()>=2)
    {
        auto u=cycles.back();
        cycles.pop_back(); 
        auto v=cycles.back();
        cycles.pop_back();
        go(u[0],v[0]); 
        while(p[u[0]]!=v[0]) go(u[0],p[u[0]]);
        while(p[v[0]]!=v[0]) go(v[0],p[v[0]]);
    }
    for(int i=1;i<=n;i++) if(invp[i]==i) singletons.push_back(i);
    if(cycles.size()&&cycles.back().size()==2)
    {
        if(singletons.size())
        {
            auto u=cycles.back();
            cycles.pop_back(); 
            int v=singletons.back();
            go(u[0],v); go(u[1],v); go(u[0],v); 
        }
    }
    while(cycles.size())
    {
        auto u=cycles.back();
        cycles.pop_back(); 
        go(u[0],u[2]); go(u[0],u[1]);
        while(p[u[2]]!=u[2]) go(u[2],p[u[2]]);
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}