#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int prelen[MAXN],suflen[MAXN];
int dp[MAXN];
int precnt[MAXN];
int ans[MAXN];
int x[MAXN],y[MAXN];
vector<P> query[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        query[x[i]].push_back(P(y[i],i));
    }
    fill(dp+1,dp+n+1,INF);
    for(int i=1;i<=n;i++)
    {
        prelen[i]=lower_bound(dp+1,dp+n+1,a[i])-dp;
        for(auto p:query[i]) ans[p.S]+=lower_bound(dp+1,dp+n+1,p.F)-dp;
        *lower_bound(dp+1,dp+n+1,a[i])=a[i];
    }
    fill(dp+1,dp+n+1,INF);
    for(int i=n;i>=1;i--)
    {
        suflen[i]=lower_bound(dp+1,dp+n+1,-a[i])-dp;
        for(auto p:query[i]) ans[p.S]+=lower_bound(dp+1,dp+n+1,-p.F)-dp-1;
        *lower_bound(dp+1,dp+n+1,-a[i])=-a[i];
    }
    int len=lower_bound(dp+1,dp+n+1,INF)-dp-1;
    for(int i=1;i<=n;i++) if(prelen[i]+suflen[i]-1==len) precnt[prelen[i]]++;
    for(int i=1;i<=m;i++)
    {
        if(ans[i]==len+1) printf("%d\n",len+1);
        else if(prelen[x[i]]+suflen[x[i]]-1==len&&precnt[prelen[x[i]]]==1&&ans[i]!=len) printf("%d\n",len-1);
        else printf("%d\n",len);
    }
    return 0;
}