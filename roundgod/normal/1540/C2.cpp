#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define MAXQ 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],b[MAXN],c[MAXN];
int x[MAXQ];
int sb[MAXN],sa[MAXN];
int dp[MAXN][MAXM];
int ans[405];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n-1;i++) scanf("%d",&b[i]);
    sb[1]=0;
    for(int i=2;i<=n;i++) sb[i]=sb[i-1]+b[i-1];
    for(int i=2;i<=n;i++) sb[i]+=sb[i-1];
    int lb=INF,rb=INF;
    scanf("%d",&q);
    for(int i=1;i<=q;i++) scanf("%d",&x[i]);
    //calculating lower bound
    for(int i=1;i<=n;i++)
    {
        sa[i]=0;
        lb=min(lb,(sa[i]-sb[i])/i);
        while(lb*i>sa[i]-sb[i]) lb--;
    }
    //calculating upper bound
    for(int i=1;i<=n;i++)
    {
        sa[i]=sa[i-1]+c[i];
        rb=min(rb,(sa[i]-sb[i])/i);
        while(rb*i>sa[i]-sb[i]) rb--;
    }
    lb--; rb++;
    ll s=0;
    for(int val=lb;val<=rb;val++)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1; dp[0][1]=MOD-1;
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=10000;j++) add(dp[i][j],dp[i][j-1]);
            for(int j=0;j<=10000;j++)
            {
                if(i>0&&j-sb[i]<1LL*val*i) dp[i][j]=0; 
                if(!dp[i][j]) continue;
                if(i<n)
                {
                    add(dp[i+1][j],dp[i][j]);
                    dec(dp[i+1][j+c[i+1]+1],dp[i][j]);
                }
            }
        }
        for(int j=0;j<=10000;j++) add(ans[val-lb],dp[n][j]);
    }
    for(int i=1;i<=q;i++)
    {
        if(x[i]<lb) printf("%d\n",ans[0]);
        else if(x[i]>rb) printf("%d\n",0);
        else printf("%d\n",ans[x[i]-lb]);
    }
    return 0;
}