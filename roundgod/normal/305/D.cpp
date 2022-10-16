#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,k;
bool has[MAXN];
int fact[MAXN],invf[MAXN];
int sum[MAXN];
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    memset(has,false,sizeof(has));
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&m,&k);
    int cnt=0,l=INF,r=-INF;
    bool f=true;
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(v-u!=1&&v-u!=k+1) f=false;
        else if(v-u==k+1&&!has[u])
        {
            has[u]=true;
            l=min(l,u);
            r=max(r,u);
            cnt++;
        }
    }
    if(!f||r-l>=k+1)
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(has[i]?1:0);
    int ans=0;
    for(int i=1;i<=l&&i+k+1<=n;i++)
    {
        if(i+k+1<=r) continue;
        int lb=i,rb=min(i+k,n-k-1);
        int len=rb-lb,cc=sum[rb]-sum[lb-1];
        if(has[i]) add(ans,pow_mod(2,len-(cc-1))); else add(ans,pow_mod(2,len-cc));
        if(has[i]) dec(ans,1);
    }
    add(ans,1);
    printf("%d\n",ans);
    return 0;
}