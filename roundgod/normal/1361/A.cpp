#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN];
int t[MAXN];
vector<int> v;
vector<P> vv;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    bool f=true;
    for(int i=1;i<=n;i++)
    {
        v.clear();
        for(auto to:G[i])
        {
            if(t[to]==t[i]) f=false;
            else if(t[to]<t[i]) v.push_back(t[to]);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.size()!=t[i]-1) f=false;
    }
    if(!f) puts("-1");
    else
    {
        for(int i=1;i<=n;i++) vv.push_back(P(t[i],i));
        sort(vv.begin(),vv.end());
        for(auto p:vv) printf("%d ",p.S);
    }
    return 0;
}