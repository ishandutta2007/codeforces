#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
 
using namespace std;
typedef long long LL;
const int N=100005,mod=998244353;
int n,m,x,inv2,len,bin[N<<2];
LL a[N<<2],b[N<<2],c[N<<2],B[N<<2],C[N<<2],invb[N<<2],G[N<<2];
 
int getint()
{
    char ch;
    while(!isdigit(ch=getchar()));
    int x=ch-48;
    while(isdigit(ch=getchar())) x=x*10+ch-48;
    return x;
}
 
LL getmi(LL a,LL x)
{
    LL rt=1;
    while(x)
    {
        if(x&1) rt=rt*a%mod;
        a=a*a%mod,x>>=1;
    }
    return rt;
}
 
void FFT(LL a[],int len,int tp)
{
    rep(i,0,len-1) bin[i]=bin[i>>1]>>1|((i&1)*(len>>1));
    rep(i,0,len-1) if(i<bin[i]) swap(a[i],a[bin[i]]);
    for(int i=1; i<len; i<<=1)
    {
        LL wn=getmi(3,(mod-1)/(i<<1));
        if(tp==-1) wn=getmi(wn,mod-2);
        for(int j=0; j<len; j+=i<<1)
        {
            LL w=1,x,y;
            rep(k,0,i-1)
            {
                x=a[j+k],y=a[i+j+k]*w%mod,w=w*wn%mod;
                a[j+k]=(x+y)%mod,a[i+j+k]=(x-y+mod)%mod;
            }
        }
    }
    if(tp==-1)
    {
        LL x=getmi(len,mod-2);
        rep(i,0,len-1) a[i]=a[i]*x%mod;
    }
}
 
void get_inv(LL a[],LL b[],int n)
{
    if(n==1)
    {
        b[0]=getmi(a[0],mod-2);
        return;
    }
    get_inv(a,b,n>>1);
    rep(i,0,n-1) G[i]=a[i];
    rep(i,n,2*n-1) G[i]=0;
    FFT(G,n<<1,1),FFT(b,n<<1,1);
    rep(i,0,2*n-1) b[i]=b[i]*(2-G[i]*b[i]%mod+mod)%mod;
    FFT(b,n<<1,-1);
    rep(i,n,2*n-1) b[i]=0;
}
 
void get_sqrt(LL a[],LL b[],int n)
{
    if(n==1)
    {
        b[0]=1;
        return;
    }
    get_sqrt(a,b,n>>1);
    rep(i,0,n-1) invb[i]=0;
    get_inv(b,invb,n);
    rep(i,0,n-1) G[i]=a[i]; 
    rep(i,n,2*n-1) G[i]=0;
    FFT(G,n<<1,1),FFT(invb,n<<1,1);
    rep(i,0,2*n-1) G[i]=G[i]*invb[i]%mod*inv2%mod;
    FFT(G,n<<1,-1);
    rep(i,0,n-1) b[i]=(b[i]*inv2+G[i])%mod;
}
 
int main()
{
    n=getint(),m=getint(),inv2=getmi(2,mod-2);
    rep(i,1,n) if((x=getint())<=m) a[x]=1;
    for(len=1; len<=(m+1); len<<=1);
    rep(i,0,m) C[i]=4*(mod-a[i])%mod;
    ++C[0],get_sqrt(C,c,len),++c[0];
    get_inv(c,b,len);
    rep(i,1,m) printf("%lld\n",b[i]*2%mod);
    return 0;
}