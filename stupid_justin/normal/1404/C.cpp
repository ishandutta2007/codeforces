#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=3e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=1ll*ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return 1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
struct treearray
{
    int a[N],n;
    void clear(int m){n=m;for (int i=0;i<=n;i++) a[i]=0;}
    void add(int i,int x){for (;i<=n;i+=i&-i) a[i]+=x;}
    int query(int i){int ret=0;for (;i;i^=i&-i) ret+=a[i];return ret;}
    int operator[](int x) {return query(x);}
    int kth(int k){int ret=0;for (int i=(1<<18);i>=1;i>>=1) if (ret+i<=n && k-a[ret+i]>0) ret+=i,k-=a[ret];return ret+1;}
}T;
int n,m,a[N],ans[N];
struct Query{int l,r,id;}Q[N];
bool cmp(Query a,Query b){return a.r<b.r;}

signed main()
{
	rd(n);rd(m);T.clear(n);
    for (int i=1;i<=n;i++) rd(a[i]),a[i]=i-a[i];
    for (int i=1;i<=m;i++) rd(Q[i].l),rd(Q[i].r),Q[i].l++,Q[i].r=n-Q[i].r,Q[i].id=i;
    sort(Q+1,Q+m+1,cmp);int p=1;
    for (int i=1;i<=m;i++){int k;while (p<=Q[i].r) k=a[p]<0?1:min(T.kth(p-a[p]),p+1),T.add(k,1),p++;ans[Q[i].id]=Q[i].r-T[Q[i].l];}
    for (int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}
/*
*/