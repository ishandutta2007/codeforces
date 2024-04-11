#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=1e6+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
struct treearray
{
    int a[N],n;
    void clear(int m){n=m;for (int i=0;i<=m;i++) a[i]=0;}
    void add(int i,int x){if (i==0) return;for (;i<=n;i+=i&-i) a[i]+=x;}
    int query(int i){if (i==0) return 0;int ret=0;for (;i;i^=i&-i) ret+=a[i];return ret;}
    int operator[](int x) {return query(x);}
}T;
int n,m,k,p,ans=-inf;
int A[N],a[N],b[N],c[N];
int solve(int l,int r)
{
    // m  p 
    if (r-l+1<p) return -inf;if (r<l) return -inf;if (l==r) {if (p==1 || m==1) return a[l];if (p==0) return 0;return -inf;}
    for (int i=0;i<m;i++) b[i]=c[i]=-inf;b[0]=c[0]=0;
    int mid=(l+r)/2;int sl=0,sr=0,ret=-inf;
    for (int i=mid;i>=l;i--) sl+=a[i],b[(mid-i+1)%m]=max(b[(mid-i+1)%m],sl);
    for (int i=mid+1;i<=r;i++) sr+=a[i],c[(i-mid)%m]=max(c[(i-mid)%m],sr);
    for (int i=0;i<min(m,mid-l+2);i++) ret=max(ret,b[i]+c[(p+m-i)%m]); 
    //for (int i=0;i<m;i++) printf("b[%lld]=%lld,",i,b[i]);cout<<endl;
    //for (int i=0;i<m;i++) printf("c[%lld]=%lld,",i,c[i]);cout<<endl;
    //printf("p=%lld,solve(%lld,%lld)=%lld\n",p,l,r,ret);
    return max({ret,solve(l,mid),solve(mid+1,r)});
}
signed main()
{
    rd(n);rd(m);rd(k);
    for (int i=1;i<=n;i++) rd(A[i]);
    for (int i=1;i<=n;i++) a[i]=m*A[i]-k;
    //for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    for (int i=0;i<m;i++) 
    {
        p=i;
        int x=solve(1,n);
        //cout<<"p="<<p<<",x="<<x<<endl;
        ans=max(ans,(x-k*((m-p)%m))/m);
    }
    cout<<ans<<endl;
}
/*

*/