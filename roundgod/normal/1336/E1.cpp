#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
ll a[MAXN];
ll bas[40];
int ans[MAXN];
map<ll,int> dp[40],ndp[40];
int n,m;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int cnt=1;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        ll x=a[i];
        for(int j=34;j>=0;j--)
        {
            if(x&(1ll<<j))
            {
                if(!bas[j])
                {
                    bas[j]=x; num++;
                    for(int k=j+1;k<=34;k++) if(bas[k]) bas[k]^=bas[j];
                    break;
                }
                x^=bas[j];
            }
        }
        if(!x) cnt=2LL*cnt%MOD;
    }
    dp[0][0]=1;
    for(int i=0;i<=34;i++)
    {
        int cur=34-i;
        if(!bas[cur]) continue;
        for(int j=0;j<=35;j++) ndp[j].clear();
        for(int j=0;j<=35;j++)
        {
            for(auto p:dp[j])
            {
                int tmp=__builtin_popcountll(p.F>>cur);
                add(ndp[j+tmp][p.F&((1LL<<cur)-1)],p.S);
                tmp=__builtin_popcountll((p.F^bas[cur])>>cur);
                add(ndp[j+tmp][(p.F^bas[cur])&((1LL<<cur)-1)],p.S);
            }
        }
        for(int j=0;j<=35;j++) swap(dp[j],ndp[j]);
    }
    for(int j=0;j<=35;j++) 
        for(auto p:dp[j])
            add(ans[j+__builtin_popcountll(p.F)],p.S);
    for(int j=0;j<=m;j++) printf("%d ",1LL*ans[j]*cnt%MOD);
    return 0;
}