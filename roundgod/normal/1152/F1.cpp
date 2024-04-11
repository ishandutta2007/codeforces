#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 13
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,m;
int dp[MAXK][(1<<4)],ndp[MAXK][(1<<4)];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    dp[0][0]=1;
    int all=(1<<m)-1;
    for(int i=n;i>=1;i--)
    {
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=k;j++)
        {
            for(int mask=0;mask<(1<<m);mask++)
            {
                if(!dp[j][mask]) continue;
                int nmask=(mask<<1)&all;
                add(ndp[j][nmask],dp[j][mask]);
                if(j<k) add(ndp[j+1][nmask|1],1LL*(__builtin_popcount(mask)+1)*dp[j][mask]%MOD);
            }
        }
        swap(dp,ndp);
    }
    int ans=0;
    for(int i=0;i<(1<<m);i++) add(ans,dp[k][i]);
    printf("%d\n",ans);
    return 0;
}