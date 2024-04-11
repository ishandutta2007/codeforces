#include<bits/stdc++.h>
#define MAXN 3000010
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int fact[MAXN],invf[MAXN];
int f[MAXN][3];
int n,q;
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
    fact[0]=invf[0]=1;
    for(int i=1;i<=3000005;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[3000005]=pow_mod(fact[3000005],MOD-2);
    for(int i=3000004;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&q);
    f[3*n][0]=1; f[3*n][1]=3*n+1; f[3*n][2]=comb(3*n+2,3*n);
    for(int i=3*n-1;i>=1;i--)
    {
        f[i][0]=f[i+1][1]; dec(f[i][0],f[i+1][0]);
        f[i][1]=f[i+1][2]; dec(f[i][1],f[i+1][1]);
        f[i][2]=f[i+1][0]; add(f[i][2],comb(3*n+3,i+1)); dec(f[i][2],comb(3,i+1)); dec(f[i][2],f[i+1][2]);
    }
    for(int i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",f[x][0]);
    }
    return 0;
}