#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int n;
int fact[MAXN],invf[MAXN];
string save[MAXN];
int a[MAXN],b[MAXN];
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
    for(int i=1;i<=(1<<18);i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[(1<<18)]=pow_mod(fact[(1<<18)],MOD-2);
    for(int i=(1<<18)-1;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&n);
    scanf("%s",str+1);
    int ans=1;
    int base=19260817;
    for(int i=(1<<(n-1));i<(1<<n);i++) save[i]=(str[i]=='A'?"A":"B");
    for(int i=(1<<(n-1))-1;i>=1;i--)
    {
        if(save[i*2]!=save[i*2+1]) ans=2LL*ans%MOD;
        if(save[i*2]>save[i*2+1]) swap(save[i*2],save[i*2+1]);
        save[i]=(str[i]=='A'?"A":"B");
        save[i]+=save[i*2]; save[i]+=save[i*2+1];
    }
    printf("%d\n",ans);
    return 0;
}