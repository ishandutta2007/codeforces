#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
int posa[MAXM],posb[MAXM];
ll M[3],C[3];
ll k;
ll exgcd(ll a, ll b, ll &x, ll &y) 
{
    if (b == 0) {x = 1, y = 0; return a;}
    ll r = exgcd(b, a % b, x, y), tmp;
    tmp = x; x = y; y = tmp - (a / b) * y;
    return r;
}
ll inv(ll a, ll b) 
{
    ll x,y;
    ll r = exgcd(a, b, x, y);
    while (x < 0) x += b;
    return x;
}
ll excrt()
{
    bool flag = 1;
    for (ll i = 2; i <= 2; i++) 
    {
        ll M1 = M[i - 1], M2 = M[i], C2 = C[i], C1 = C[i - 1], T = __gcd(M1, M2);
        if ((C2 - C1) % T != 0) {flag = 0; break;}
        M[i] = (M1 * M2) / T;
        C[i] = ( inv( M1 / T , M2 / T ) * (C2 - C1) / T ) % (M2 / T) * M1 + C1;
        C[i] = (C[i] % M[i] + M[i]) % M[i];
    }
    return (flag ? C[2] : -1);
}
vector<ll> id;
int main()
{
    scanf("%d%d%lld",&n,&m,&k);
    memset(posa,-1,sizeof(posa));
    memset(posb,-1,sizeof(posb));
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        posa[a[i]]=i-1;
    }
    for(int i=1;i<=m;i++) 
    {
        scanf("%d",&b[i]);
        posb[b[i]]=i-1;
    }
    for(int i=1;i<=2*max(n,m);i++)
    {
        if(posa[i]==-1||posb[i]==-1) continue;
        M[1]=n; C[1]=posa[i];
        M[2]=m; C[2]=posb[i];
        ll res=excrt();
        if(res!=-1) id.push_back(res);
    }
    sort(id.begin(),id.end());
    ll lcm=1LL*n*m/__gcd(n,m);
    ll ans=0;
    ll round=(k-1)/(lcm-(int)id.size());
    ans+=round*lcm;
    k-=round*(lcm-(int)id.size());
    ll cur=0;
    for(int i=0;i<(int)id.size();i++)
    {
        if(k<=id[i]-cur)
        {
            ans+=k;
            printf("%lld\n",ans);
            return 0;
        }
        k-=(id[i]-cur);
        ans+=id[i]-cur+1;
        cur=id[i]+1;
    }
    ans+=k;
    printf("%lld\n",ans);
    return 0;
}