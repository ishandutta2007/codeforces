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
const int inf=0x3f3f3f3f3f3f3f3f;
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
int n,q,cnt,k,idx;
int l[N],r[N],X[N],Y[N],col[N],pre[N],la[N],ans[N];
map<pii,int> H;
struct Query{int l,r,id;}Q[N];
bool cmp(Query a,Query b) {return (a.r==b.r?a.l<b.l:a.r<b.r);}
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++)
    {
        rd(k);l[i]=cnt+1;r[i]=l[i]+k-1;
        for (int j=1;j<=k;j++) rd(X[j]),rd(Y[j]);
        for (int j=1;j<=k;j++)
        {
            int t=j+1;if (t==k+1) t=1;
            int x=X[j]-X[t],y=Y[j]-Y[t];
            int g=__gcd(abs(x),abs(y));x/=g;y/=g;
            pii p=mp(x,y);if (!H[p]) H[p]=++idx;col[++cnt]=H[p];
        }
    }
    T.clear(cnt);
    for (int i=1;i<=cnt;i++) pre[i]=la[col[i]],la[col[i]]=i;
    rd(q);for (int i=1,x,y;i<=q;i++) rd(x),rd(y),Q[i].id=i,Q[i].l=l[x],Q[i].r=r[y];
    sort(Q+1,Q+q+1,cmp);int p=1;
    for (int i=1;i<=q;i++)
    {
        while (p<=Q[i].r) T.add(p,1),T.add(pre[p],-1),p++;
        ans[Q[i].id]=T[Q[i].r]-T[Q[i].l-1];
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
/*

*/