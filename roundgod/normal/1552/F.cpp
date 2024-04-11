#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN],s[MAXN];
int dp[MAXN],sum[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d",&x[i],&y[i],&s[i]);
        v.push_back(x[i]);
    }
    sum[0]=0;
    int ans=(x[n]+1)%MOD;
    for(int i=1;i<=n;i++)
    {
        dp[i]=(x[i]-y[i])%MOD;
        int pos=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;
        add(dp[i],sum[i-1]);
        dec(dp[i],sum[pos-1]);
        sum[i]=sum[i-1];
        add(sum[i],dp[i]);
    }
    for(int i=1;i<=n;i++) if(s[i]) add(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}