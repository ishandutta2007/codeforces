#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,w[MAXN];
vector<int> G[MAXN];
priority_queue<int> pque;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        ll ans=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&w[i]);
            ans+=w[i];
        }
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<(int)G[i].size()-1;j++) pque.push(w[i]);
        }
        printf("%lld",ans);
        for(int i=0;i<n-2;i++)
        {
            int v=pque.top(); pque.pop();
            ans+=v;
            printf("% lld",ans);
        }
        puts("");
    }
    return 0;
}