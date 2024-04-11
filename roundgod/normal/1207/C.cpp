#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
string str;
ll dp[MAXN][2];
int n,a,b;
void update(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&a,&b);
        cin>>str;
        for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=INF;
        dp[0][0]=b;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(dp[i][j]==INF) continue;
                for(int k=0;k<2;k++)
                {
                    if((str[i]=='1'||(i!=n-1&&str[i+1]=='1'))&&(!k)) continue;
                    update(dp[i+1][k],dp[i][j]+(k+1)*b+(j==k?a:2*a));
                }
            }
        }
        printf("%lld\n",dp[n][0]);
    }
    return 0;
}