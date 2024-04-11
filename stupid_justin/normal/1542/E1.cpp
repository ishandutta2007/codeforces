#include<bits/stdc++.h>
#define int long long
#define f(a,b) F[a][b+M]
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=505*505;
const int M=N/2;
const int SZ=450;
int mod=998244353;
const int inf=0x3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,ans;
int a[N];
int F[2][N];
int fac[N],suf[N];
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
signed main()
{
    rd(n);rd(mod);
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*(n-i+1)%mod;
    f(0,0)=1;
    int t=0;
    for (int i=1;i<n;i++)
    {
        t^=1;
        memset(F[t],0,sizeof(F[t]));
        int x=(i+1)*(i+1)/2;
        for (int j=-x;j<=x;j++) 
        {
            int y=f(t^1,j);
            if (y) add(f(t,j+i+1),y),add(f(t,j-i+1),y),f(t,j+1)+=y*(mod-2),f(t,j+1)%=mod;
        }
        for (int T=1;T<=2;T++)
        {
            for (int j=x;j>=-x;j--) add(f(t,j),f(t,j+1));
            for (int j=-x;j<=x;j++) f(t,j)=f(t,j+1);
        }
        for (int j=x;j>=0;j--) {suf[j]=(suf[j+1]+f(t,j))%mod;if (suf[j]>=mod) suf[j]-=mod;}
        for (int j=0;j<=i;j++) for (int k=j+1;k<=i;k++) ans+=fac[n-i-1]*suf[k-j+1],ans%=mod;
    }
    cout<<ans<<endl;
}
/*
*/