#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans;
ll a[MAXN];
vector<int> G[MAXN];
int d[MAXN];
vector<P> E;
void add_edge(int u,int v)
{
    G[u].push_back(v); G[v].push_back(u);
    E.push_back(P(u,v));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int j=60;j>=0;j--)
    {
        int last=-1,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]&(1LL<<j))
            {
                cnt++;
                if(cnt==3)
                {
                    puts("3");
                    return 0;
                }
                else if(last==-1) last=i;
                else add_edge(last,i);
            }
        }
    }
    sort(E.begin(),E.end());
    E.erase(unique(E.begin(),E.end()),E.end());
    ans=INF;
    for(int i=0;i<(int)E.size();i++)
    {
        for(auto e:E) d[e.F]=d[e.S]=INF;
        d[E[i].F]=0;
        queue<int> que; que.push(E[i].F);
        while(que.size())
        {
            int v=que.front(); que.pop();
            for(auto to:G[v])
            {
                if(v==E[i].F&&to==E[i].S) continue;
                if(d[to]==INF)
                {
                    d[to]=d[v]+1;
                    que.push(to);
                }
            }
        }
        if(d[E[i].S]!=INF) ans=min(ans,d[E[i].S]+1);
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}