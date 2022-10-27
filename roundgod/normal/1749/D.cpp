#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll m;
bool is_prime[MAXN];
int main()
{
    scanf("%d%lld",&n,&m);
    ll ans=m%MOD;
    ll all=m%MOD;
    ll tmp=m%MOD;
    ll cur=m%MOD;
    ll now=1;
    memset(is_prime,true,sizeof(is_prime));
    for(int i=2;i<=n;i++)
    {
        if(now<=m)
        {
            if(is_prime[i])
            {
                now=now*i;
                for(int j=2*i;j<=100000;j+=i) is_prime[j]=false;
            }
            cur=cur*((m/now)%MOD)%MOD;
            ans=(ans+cur)%MOD;
        }
        tmp=tmp*(m%MOD)%MOD;
        all=(all+tmp)%MOD;
    }
    ans=(all+MOD-ans)%MOD;
    printf("%lld\n",ans);
    return 0;
}