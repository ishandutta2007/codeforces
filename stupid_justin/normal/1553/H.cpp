#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
const int M=20;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,k;
int f[N],mn[N],mx[N];
signed main()
{
    rd(n);rd(k);
    for (int i=0;i<(1<<k);i++) f[i]=inf,mn[i]=inf,mx[i]=-inf;
    for (int i=1,x;i<=n;i++) rd(x),mn[x]=mx[x]=0;
    for (int i=0;i<k;i++) for (int x=0;x<(1<<k);x++) if (x>>i&1^1)
    {
        int y=x|(1<<i);
        f[x]=f[y]=min(f[x],f[y]);
        f[x]=min(f[x],(1LL<<i)+mn[y]-mx[x]);
        f[y]=min(f[y],(1LL<<i)+mn[x]-mx[y]);
        int mnx,mny,mxx,mxy;
        mnx=mn[x],mny=mn[y],mxx=mx[x],mxy=mx[y];
        mn[x]=min(mnx,mny+(1LL<<i));mx[x]=max(mxx,mxy+(1LL<<i));
        mn[y]=min(mny,mnx+(1LL<<i));mx[y]=max(mxy,mxx+(1LL<<i));
    }
    for (int i=0;i<(1<<k);i++) cout<<f[i]<<" ";cout<<endl;

    
}
/*

*/