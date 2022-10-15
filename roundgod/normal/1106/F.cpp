#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXK 105
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,k,m,M,b[MAXK];
int g=3,now,t,ans;
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
mat mul(mat A,mat B,int p)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<(int)A.size();i++)
        for(int k=0;k<(int)B.size();k++)
            for(int j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%p;
    return C;
}
mat _pow(mat A,ll n,int p)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<(int)A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A,p);
        A=mul(A,A,p);
        n>>=1;
    }
    return B;
};
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m)
{
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
map<int,int> mp;
int find_order(int x)
{
    now=x;
    for(int i=0;i<=30000;++i)   
    {    
        if(mp.count(now))
        {
            ans=(1LL*i*M%MOD+mp[now])%MOD;
            return ans;
        }
        now=1LL*now*t%MOD;
    }
    return -1;
}
int main()
{
    scanf("%d",&k);
    for(int i=0;i<k;i++) scanf("%d",&b[i]);
    scanf("%d%d",&n,&m);
    mat A(k,vec(k));
    for(int i=0;i<k;i++) A[0][i]=b[i];
    for(int i=1;i<k;i++)
        for(int j=0;j<k;j++)
            A[i][j]=(j==i-1?1:0);
    mat x(k,vec(1));
    x[0][0]=1;
    for(int i=1;i<k;i++) x[i][0]=0;
    A=_pow(A,n-k,MOD-1);
    x=mul(A,x,MOD-1);
    int res=x[0][0];
    //X^res=m(mod p)
    //find X
    M=40000;
    int now=1;mp[now]=0,t=pow_mod(g,M);t=pow_mod(t,MOD-2);
    for(int i=1;i<=M;i++)
    {
        now=1LL*now*g%MOD;
        if(!mp.count(now)) mp[now]=i; else break;
    }
    int ord=find_order(m),mod=MOD-1;
    res%=mod; ord%=mod;
    if(ord==0)
    {
        puts("1");
        return 0;
    }
    if(res==0)
    {
        puts("-1");
        return 0;
    }
    int gg=__gcd(res,ord);
    res/=gg; ord/=gg;
    //printf("%d %d %d\n",res,ord,mod);
    if(__gcd(res,mod)!=1)
    {
        puts("-1");
        return 0;
    }
    int o=1LL*ord*mod_inverse(res,mod)%mod;
    int ans=pow_mod(g,o);
    printf("%d\n",ans);
    return 0;
}