#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int n,p,k;
ll ans;
ll a[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
string str;
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
vector<ll> factors;
void factorize(ll x)
{
    factors.clear();
    ll tmp=x;
    for(int i=0;i<p;i++)
    {
        if(tmp%prime[i]==0)
        {
            factors.push_back(prime[i]);
            while(tmp%prime[i]==0) tmp/=prime[i];
        }
    }
    if(tmp>1) factors.push_back(tmp);
}
void update(ll pr)
{
    ll s=0;
    for(int i=1;i<=n;i++) 
    {
        ll x=a[i]%pr;
        if(a[i]<pr) s+=pr-x; else s+=min(x,pr-x);
    }
    ans=min(ans,s);
}
void go(ll x)
{
    if(x<2) return;
    factorize(x);
    for(auto pr:factors) update(pr);
}
int sieve(int n)
{
    p=0;
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
int main()
{
    int p=sieve(1000000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    ans=n;
    for(int trials=0;trials<20;trials++)
    {
        int id=wcy()%n+1;
        go(a[id]); go(a[id]+1); go(a[id]-1);
    }
    printf("%lld\n",ans);
    return 0;
}