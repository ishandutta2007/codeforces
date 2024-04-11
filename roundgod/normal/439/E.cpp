#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int prime[MAXN],miu[MAXN];
bool is_prime[MAXN];
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int q,n,f;
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
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    memset(miu,0,sizeof(miu));
    miu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; miu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    int p=sieve(100000);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&f);
        int ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i) continue;
            if(miu[i]==1) add(ans,comb(n/i-1,f-1)); else if(miu[i]==-1) dec(ans,comb(n/i-1,f-1));
            if(i*i!=n)
            {
                int x=n/i;
                if(miu[x]==1) add(ans,comb(n/x-1,f-1)); else if(miu[x]==-1) dec(ans,comb(n/x-1,f-1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}