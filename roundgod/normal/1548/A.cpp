#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN];
set<int> G[MAXN];
int ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].insert(v); G[v].insert(u);
    }
    ans=0;
    for(int i=1;i<=n;i++) if(G[i].size()==0||*(--G[i].end())<i) ans++;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int type,u,v;
        scanf("%d",&type);
        if(type==3) {printf("%d\n",ans); continue;}
        else
        {
            scanf("%d%d",&u,&v);
            if(G[u].size()==0||*(--G[u].end())<u) ans--;
            if(G[v].size()==0||*(--G[v].end())<v) ans--;
            if(type==1) {G[u].insert(v); G[v].insert(u);}
            else {G[u].erase(v); G[v].erase(u);}
            if(G[u].size()==0||*(--G[u].end())<u) ans++;
            if(G[v].size()==0||*(--G[v].end())<v) ans++;
        }
    }
    return 0;
}