#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,k,a[MAXN];
vector<int> G[MAXN];
int color[MAXN],dp[MAXN];
vector<int> order;
bool flag;
void dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0) dfs_visit(to);
        else if(color[to]==1) flag=false;
	}
	color[v]=2;
	order.push_back(v);
}
void toposort()
{
    flag=true; order.clear();
	for(int i=1;i<=n;i++) color[i]=0;
	for(int i=1;i<=n;i++)
		if(color[i]==0)
			dfs_visit(i);
    reverse(order.begin(),order.end());
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=0;j<x;j++)
            {
                int y;
                scanf("%d",&y);
                G[y].push_back(i);
            }
        }
        toposort();
        for(int i=1;i<=n;i++) dp[i]=0;
        if(!flag) {puts("-1"); continue;}
        int ans=0;
        for(auto x:order)
        {
            dp[x]=max(dp[x],1);
            ans=max(ans,dp[x]);
            for(auto to:G[x])
            {
                if(to>x) dp[to]=max(dp[to],dp[x]);
                else dp[to]=max(dp[to],dp[x]+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}