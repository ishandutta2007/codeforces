#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int t,n,m;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
mt19937_64 wcy(time(NULL));
ull seed[MAXN];
ull val[MAXN];
map<ull,ll> mp;
ll c[MAXN];
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
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) val[i]=0;
        for(int i=1;i<=n;i++) seed[i]=wcy();
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            val[v]^=seed[u];
        }
        for(int i=1;i<=n;i++) mp[val[i]]+=c[i];
        ll ans=0;
        for(auto p:mp)
        {
            if(p.F==0) continue;
            ans=__gcd(ans,p.S);
        }
        printf("%lld\n",ans);
    }
    return 0;
}