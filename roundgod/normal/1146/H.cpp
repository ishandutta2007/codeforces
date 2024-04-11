#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN];
vector<pair<double,P> > v;
ll dp[MAXN][MAXN][6];
void add(ll &a,ll b) {a+=b;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            double ang=atan2(y[j]-y[i],x[j]-x[i]);
            v.push_back(make_pair(ang,P(i,j)));
        }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++) dp[i][i][0]=1;
    for(int i=0;i<(int)v.size();i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<5;k++)
                add(dp[j][v[i].S.S][k+1],dp[j][v[i].S.F][k]);
    ll ans=0;
    for(int i=1;i<=n;i++) add(ans,dp[i][i][5]);
    printf("%lld\n",ans);
    return 0;
}