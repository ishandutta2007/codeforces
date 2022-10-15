#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
vector<P> G[MAXN];
bool del[MAXN];
vector<int> matching,indset;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        matching.clear(); indset.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=3*n;i++) G[i].clear(),del[i]=false;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(P(v,i));
            G[v].push_back(P(u,i));
        }
        for(int i=1;i<=3*n;i++)
        {
            if(del[i]) continue;
            bool f=false;
            for(auto p:G[i])
            {
                if(!del[p.F])
                {
                    del[p.F]=true;
                    f=true;
                    matching.push_back(p.S);
                    break;
                }
            }
            if(!f) indset.push_back(i);
            del[i]=true;
        }
        if(matching.size()>=n)
        {
            puts("Matching");
            for(int i=0;i<n;i++) printf("%d ",matching[i]);
            puts("");
        }
        else
        {
            puts("IndSet");
            for(int i=0;i<n;i++) printf("%d ",indset[i]);
            puts("");
        }
    }
}