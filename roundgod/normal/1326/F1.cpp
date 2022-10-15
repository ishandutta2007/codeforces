#include<bits/stdc++.h>
#define MAXN 15
#define MASK (1<<14)
#define MAXM 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
void add(ll &a,ll b) {a+=b;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
 
char str[MAXN][MAXN];
int popcnt[MASK];
ll dp[MAXM],ndp[MAXM];
int maxi[MAXN];
int cnt[MAXN],id[MASK];
int pos[MASK][MAXN],rpos[MASK][MAXN];
ll ans[MASK];
vector<int> G[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<(1<<n);i++) popcnt[i]=__builtin_popcount(i);
    for(int i=1;i<(1<<n);i++) 
    {
        id[i]=cnt[popcnt[i]];
        cnt[popcnt[i]]++;
        G[popcnt[i]].push_back(i);
        int tot=0;
        for (int j=0;j<n;j++) 
        {
            if((i>>j)&1) 
            {
                pos[i][tot]=j;
                rpos[i][j]=tot++;
            }
        }
    }
    for(int i=1;i<=n;i++) maxi[i]=1LL*(cnt[i]*i)*(1<<(i-1));
    for(int i=0;i<n;i++) dp[i]=1;
    for(int i=1;i<n;i++)
    {
        int fmask=(1<<(i-1))-1;
        for (int j=0;j<maxi[i+1];j++) ndp[j]=0;
        for (int j=0;j<maxi[i];j++)
        {
            ll tmp=dp[j];
            int tmp2=j&fmask,smask=j>>(i-1);
            int mask=G[i][smask/i];
            int s=pos[mask][smask%i];
            for (int k=0;k<n;k++) 
            {
                if (!(mask&(1<<k)))
                {
                    int nval=tmp2*2+(str[s][k]=='1'?1:0);
                    int nmask=mask|(1<<k);
                    add(ndp[((1LL*id[nmask]*(i+1)+rpos[nmask][k])<<i)|nval],tmp);
                }
            }
        }
        swap(dp,ndp);
    }
    int fmask=(1<<(n-1))-1;
    for (int i=0;i<maxi[n];i++) add(ans[i&fmask],dp[i]);
    for (int i=0;i<(1<<(n-1));i++) printf("%lld ",ans[i]);
    puts("");
    return 0;
}