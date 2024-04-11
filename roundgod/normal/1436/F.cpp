#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int prime[MAXN],mu[MAXN];
bool is_prime[MAXN];
int pow_mod(int a,int i)
{
    if(i<0) i+=MOD-1;
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void genmu(int n)
{
    int p=0;
    memset(mu,0,sizeof(mu));
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; mu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            mu[i*prime[j]]=i%prime[j]?-mu[i]:0;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
}
struct node
{
    int cnt[6];
    void merge(node &rhs)
    {
        int tmp[6];
        tmp[5]=1LL*cnt[5]*rhs.cnt[5]%MOD;
        tmp[4]=1LL*cnt[4]*rhs.cnt[5]%MOD; add(tmp[4],1LL*cnt[5]*rhs.cnt[4]%MOD);
        tmp[3]=1LL*cnt[3]*rhs.cnt[5]%MOD; add(tmp[3],1LL*rhs.cnt[3]*cnt[5]%MOD); add(tmp[3],2LL*cnt[2]*rhs.cnt[2]%MOD);
        tmp[2]=1LL*cnt[2]*rhs.cnt[5]%MOD; add(tmp[2],1LL*rhs.cnt[2]*cnt[5]%MOD);
        tmp[1]=1LL*cnt[1]*rhs.cnt[5]%MOD; add(tmp[1],1LL*rhs.cnt[1]*cnt[5]%MOD); 
        add(tmp[1],1LL*cnt[2]*rhs.cnt[4]%MOD); add(tmp[1],1LL*cnt[4]*rhs.cnt[2]%MOD);
        tmp[0]=1LL*cnt[0]*rhs.cnt[5]%MOD; add(tmp[0],1LL*rhs.cnt[0]*cnt[5]%MOD); 
        add(tmp[0],2LL*cnt[1]*rhs.cnt[2]%MOD); add(tmp[0],2LL*cnt[2]*rhs.cnt[1]%MOD); 
        add(tmp[0],1LL*cnt[3]*rhs.cnt[4]%MOD);  add(tmp[0],1LL*cnt[4]*rhs.cnt[3]%MOD);
        for(int i=0;i<6;i++) cnt[i]=tmp[i];
    }
    void init(P p)
    {
        if(p.S==0)
        {
            for(int i=0;i<5;i++) cnt[i]=0;
            cnt[5]=1;
        }
        else
        {
            cnt[5]=pow_mod(2,p.S);
            cnt[4]=1LL*p.S*pow_mod(2,p.S-1)%MOD;
            cnt[3]=1LL*p.S*(p.S+1)%MOD*pow_mod(2,p.S-2)%MOD*p.F%MOD*p.F%MOD;
            cnt[2]=1LL*p.S*pow_mod(2,p.S-1)%MOD*p.F%MOD;
            cnt[1]=1LL*p.S*(p.S+1)%MOD*pow_mod(2,p.S-2)%MOD*p.F%MOD;
            cnt[0]=1LL*p.S*p.S%MOD*(p.S+3)%MOD*pow_mod(2,p.S-3)%MOD*p.F%MOD*p.F%MOD;
        }
    }
};
node save[MAXN];
int n;
int main()
{
    genmu(100000);
    scanf("%d",&n);
    for(int i=1;i<=100000;i++) save[i].init(P(0,0));
    for(int i=1;i<=n;i++)
    {
        P p;
        scanf("%d%d",&p.F,&p.S);
        node tmp; 
        tmp.init(p);
        for(int j=1;j*j<=p.F;j++)
        {
            if(p.F%j) continue;
            save[j].merge(tmp);
            if(j*j!=p.F) save[p.F/j].merge(tmp);
        }
    }
    int ans=0;
    for(int i=1;i<=100000;i++)
    {
        int res=save[i].cnt[0];
        dec(res,save[i].cnt[3]);
        add(ans,1LL*res*(mu[i]+MOD)%MOD);
    }
    printf("%d\n",ans);
    return 0;
}