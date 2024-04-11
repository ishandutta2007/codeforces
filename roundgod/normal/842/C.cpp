#include<bits/stdc++.h>
#define MAXN 200205
using namespace std;
typedef long long ll;
typedef pair<int,bool> P;
set<P> dp[MAXN];
int n;
int a[MAXN];
vector<int> G[MAXN];
bool used[MAXN];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        if(!used[G[v][i]])
        {
            int x=G[v][i];
            for(set<P>::iterator it=dp[v].begin();it!=dp[v].end();it++)
            {
                int q=((P)*it).first;
                bool f=((P)*it).second;
                if(f) { dp[x].insert(P(gcd(q,a[x]),true)); if(dp[x].find(P(gcd(q,a[x]),false))!=dp[x].end()) dp[x].erase(P(gcd(q,a[x]),false)); if(dp[x].find(P(q,true))==dp[x].end())dp[x].insert(P(q,false));}
                else if (dp[x].find(P(gcd(q,a[x]),true))==dp[x].end()) dp[x].insert(P(gcd(q,a[x]),false));
            }
            dfs(x);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&x,&y);
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dp[0].insert(P(0,false));
    dp[0].insert(P(a[0],true));
    dfs(0);
    for(int i=0;i<n;i++)
    {
        int ans=0;
        for(set<P>::iterator it=dp[i].begin();it!=dp[i].end();it++)
        {
            int q=((P)*it).first;
            ans=max(ans,q);
        }
        if(i!=n-1) printf("%d ",ans); else printf("%d",ans);
    }
    return 0;
}