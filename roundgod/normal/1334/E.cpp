#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,a[MAXN];
ll D;
int q;
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<ll> f;
vector<int> tmp;
int solve(ll x)
{
    tmp.clear();
    int sum=0;
    for(auto y:f)
    {
        int cnt=0;
        while(x%y==0) x/=y,cnt++;
        if(cnt) tmp.push_back(cnt);
        sum+=cnt;
    }
    int res=fact[sum];
    for(auto y:tmp) res=1LL*res*invf[y]%MOD;
    return res;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100]=pow_mod(fact[100],MOD-2);
    for(int i=99;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%lld",&D);
    for(int i=2;1LL*i*i<=D;i++)
    {
        if(D%i==0)
        {
            f.push_back(i);
            while(D%i==0) D/=i;
        }
    }
    if(D>1) f.push_back(D);
    scanf("%d",&q);
    while(q--)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        ll g=__gcd(u,v);
        int ans=solve(u/g);
        ans=1LL*ans*solve(v/g)%MOD;
        printf("%d\n",ans);

    }
    return 0;
}