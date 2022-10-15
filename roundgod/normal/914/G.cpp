#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define REV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int cnt[MAXN],f[MAXN],g[MAXN];
int fhat[MAXLOGN][MAXN],ghat[MAXLOGN][MAXN],h[MAXLOGN][MAXN];
int fib[MAXN];
int n,m;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void subset_convolution(int f[],int g[],int fog[])
{
    
    for(int mask=0;mask<(1<<n);mask++) 
    {
        fhat[__builtin_popcount(mask)][mask]=f[mask];
        ghat[__builtin_popcount(mask)][mask]=g[mask];
    }
    for(int i=0;i<=n;i++) 
    {
        for(int j=0;j<n;j++) 
        {
            for(int mask=0;mask<(1<<n);mask++) 
            {
                if((mask&(1<<j))!=0) 
                {
                    add(fhat[i][mask],fhat[i][mask^(1<<j)]);
                    add(ghat[i][mask],ghat[i][mask^(1<<j)]);
                }
            }
        }
    }
    for(int mask=0;mask<(1<<n);mask++) 
        for(int i=0;i<=n;i++) 
            for(int j=0;j<=i;j++) 
                add(h[i][mask],1LL*fhat[j][mask]*ghat[i-j][mask]%MOD);
    for(int i=0;i<=n;i++)
        for(int j=0;j<n;j++)
            for(int mask=0;mask<(1<<n);mask++) 
                if((mask&(1<<j))!=0) 
                    dec(h[i][mask],h[i][mask^(1<<j)]);
    for(int mask=0;mask<(1<<n);mask++) fog[mask]=h[__builtin_popcount(mask)][mask];
}
void FWT(int a[],int n,int type)//0: xor 1: and 2: or    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                if(type==0) a[i+j]=(x+y)%MOD,a[i+j+d]=(x-y+MOD)%MOD;
                else if(type==1) a[i+j]=(x+y)%MOD;
                else a[i+j+d]=(x+y)%MOD;    
                //and:a[i+j]=x+y;    
                //or:a[i+j+d]=x+y;    
            }    
}    
    
void UFWT(int a[],int n,int type)//0: xor 1: and 2: or    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                if(type==0) a[i+j]=1LL*(x+y)*REV%MOD,a[i+j+d]=(1LL*(x-y)*REV%MOD+MOD)%MOD;    
                else if(type==1) a[i+j]=(x-y+MOD)%MOD;
                else a[i+j+d]=(y-x+MOD)%MOD;  
                //and:a[i+j]=x-y;    
                //or:a[i+j+d]=y-x;    
            }    
}    
int main()
{
    n=17;
    fib[0]=0; fib[1]=1;
    for(int i=2;i<(1<<n);i++) fib[i]=fib[i-1],add(fib[i],fib[i-2]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    subset_convolution(cnt,cnt,f);
    for(int i=0;i<(1<<n);i++) f[i]=1LL*f[i]*fib[i]%MOD;
    FWT(cnt,(1<<n),0); for(int i=0;i<(1<<n);i++) g[i]=1LL*cnt[i]*cnt[i]%MOD; UFWT(g,(1<<n),0); UFWT(cnt,(1<<n),0);
    for(int i=0;i<(1<<n);i++) g[i]=1LL*g[i]*fib[i]%MOD;
    for(int i=0;i<(1<<n);i++) cnt[i]=1LL*cnt[i]*fib[i]%MOD;
    FWT(cnt,(1<<n),1); FWT(f,(1<<n),1); FWT(g,(1<<n),1);
    for(int i=0;i<(1<<n);i++) f[i]=1LL*f[i]*g[i]%MOD*cnt[i]%MOD;
    UFWT(f,(1<<n),1);
    int ans=0;
    for(int i=0;i<n;i++) add(ans,f[(1<<i)]);
    printf("%d\n",ans);
    return 0;
}