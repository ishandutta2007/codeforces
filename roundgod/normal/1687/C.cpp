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
int t,n,m,a[MAXN],b[MAXN];
ll suma[MAXN],sumb[MAXN];
vector<int> G[MAXN];
int l[MAXN],r[MAXN];
bool vis[MAXN];
set<int> unvis;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
        for(int i=1;i<=n;i++) sumb[i]=sumb[i-1]+b[i];
        for(int i=0;i<=n;i++) G[i].clear();
        for(int i=1;i<=m;i++) 
        {
            scanf("%d%d",&l[i],&r[i]);
            G[l[i]-1].push_back(r[i]); G[r[i]].push_back(l[i]-1);
        }
        unvis.clear();
        for(int i=0;i<=n;i++) vis[i]=false;
        queue<int> que;
        for(int i=0;i<=n;i++)
        {
            if(suma[i]==sumb[i])
            {
                vis[i]=true;
                que.push(i);
            }
            else unvis.insert(i);
        }
        while(que.size())
        {
            int v=que.front();
            que.pop();
            for(auto to:G[v])
            {
                if(!vis[to]) continue;
                int l=min(v,to),r=max(v,to);
                while(unvis.size()&&unvis.lower_bound(l+1)!=unvis.end()&&(*unvis.lower_bound(l+1))<r) 
                {
                    auto it=unvis.lower_bound(l+1);
                    vis[*it]=true; que.push(*it);
                    unvis.erase(it);
                }
            }
        }
        if(unvis.size()) puts("NO"); else puts("YES");
    }
    return 0;
}