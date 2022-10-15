#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
vector<int> G[MAXN];
bool used[MAXN];
int dp[MAXN];
vector<int> closed;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        closed.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        for(int i=1;i<=n;i++) dp[i]=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==2) {closed.push_back(i); continue;}
            for(auto to:G[i]) dp[to]=max(dp[to],dp[i]+1);
        }
        printf("%d\n",(int)closed.size());
        for(auto x:closed) printf("%d ",x);
        puts("");
    }
    return 0;
}