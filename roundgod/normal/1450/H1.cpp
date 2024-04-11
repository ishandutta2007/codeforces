#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define INV4 748683265
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str;
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&m);
    cin>>str;
    int q=0,cntb=0,cntw=0,w=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='b') { if(i&1) cntb++; else cntw++;}
        else if(str[i]=='w') { w^=1; if(i&1) cntw++; else cntb++;}
        else q++;
    }
    int ways=0,ans=0;
    for(int i=0;i<=q;i++)
    {
        int tmp=max(cntw+i-(cntb+(q-i)),(cntb+(q-i))-(cntw+i));
        if(tmp%4) continue;
        add(ways,comb(q,i));
        add(ans,1LL*INV4*comb(q,i)%MOD*tmp%MOD);
    }
    ans=1LL*ans*pow_mod(ways,MOD-2)%MOD;
    printf("%d\n",ans);
    return 0;
}