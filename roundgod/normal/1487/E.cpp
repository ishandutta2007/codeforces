#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n[10];
vector<int> v[10];
map<int,int> banned[5][MAXN];
int dp[5][MAXN];
int cur;
vector<int> order;
bool cmp(int x,int y)
{
    return dp[cur][x]<dp[cur][y];
}
int main()
{
    scanf("%d%d%d%d",&n[1],&n[2],&n[3],&n[4]);
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=n[i];j++)
        {
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }
    for(int i=2;i<=4;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            banned[i][y][x]=1;
        }
    }
    for(int i=1;i<=n[1];i++) dp[1][i]=v[1][i-1];
    int ans=INF;
    for(int i=2;i<=4;i++)
    {
        order.clear();
        for(int j=1;j<=n[i-1];j++) 
        {
            if(dp[i-1][j]!=INF) order.push_back(j);
        }
        cur=i-1;
        sort(order.begin(),order.end(),cmp);
        for(int j=1;j<=n[i];j++)
        {
            dp[i][j]=INF;
            int now=0;
            while(now<(int)order.size()&&banned[i][j][order[now]]) now++; 
            if(now<(int)order.size()) dp[i][j]=dp[i-1][order[now]]+v[i][j-1];
            if(i==4) ans=min(ans,dp[i][j]);
        }
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}