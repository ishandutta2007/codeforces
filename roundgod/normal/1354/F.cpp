#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
multiset<P> ms;
int T,n,k;
struct node
{
    int a,b,id;
};
node a[MAXN];
ll dp[MAXN][MAXN];
int pre[MAXN][MAXN];
bool cmp(node x,node y)
{
    return y.b>x.b;
}
vector<int> v1,v2;
vector<int> ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        v1.clear(); v2.clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].a,&a[i].b);
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        memset(pre,-1,sizeof(pre));
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=min(i,k);j++)
            {
                if(dp[i][j]==-1) continue;
                if(dp[i][j]+1LL*(k-1)*a[i+1].b>dp[i+1][j])
                {
                    dp[i+1][j]=dp[i][j]+1LL*(k-1)*a[i+1].b;
                    pre[i+1][j]=0;
                }
                if(j!=k&&dp[i][j]+a[i+1].a+1LL*j*a[i+1].b>dp[i+1][j+1])
                {
                    dp[i+1][j+1]=dp[i][j]+a[i+1].a+1LL*j*a[i+1].b;
                    pre[i+1][j+1]=1;
                }
            }
        }
        int x=n,y=k;
        while(x>0)
        {
            if(pre[x][y]==0) 
            {
                v2.push_back(a[x].id);
                x--;
            }
            else
            {
                v1.push_back(a[x].id);
                x--; y--;
            }
        }
        reverse(v1.begin(),v1.end());
        printf("%d\n",(int)v1.size()+2*(int)v2.size());
        for(int i=0;i<(int)v1.size()-1;i++) printf("%d ",v1[i]);
        for(int i=0;i<(int)v2.size();i++) printf("%d %d ",v2[i],-v2[i]);
        printf("%d\n",v1.back());
    }
    return 0;
}