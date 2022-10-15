#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,k,q,a[MAXN];
int dp[MAXN][MAXN];
int coef[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) dp[0][i]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++) dp[i][j]=0;
        for(int j=1;j<=n;j++)
        {
            if(j!=1) add(dp[i][j],dp[i-1][j-1]);
            if(j!=n) add(dp[i][j],dp[i-1][j+1]); 
        }
    }
    for(int i=0;i<=k;i++) 
        for(int j=1;j<=n;j++) 
            add(coef[j],1LL*dp[i][j]*dp[k-i][j]%MOD);
    int ans=0;
    for(int i=1;i<=n;i++) add(ans,1LL*coef[i]*a[i]%MOD);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        dec(ans,1LL*coef[x]*a[x]%MOD);
        a[x]=y;
        add(ans,1LL*coef[x]*a[x]%MOD);
        printf("%d\n",ans);
    }
    return 0;
}