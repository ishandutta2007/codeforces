
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
const int N=2e6+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}


int n,m,k,ans;
int a[N],b[N],p[N],c[N];
bool cmp(int x,int y){return a[x]<a[y];}
int mn[N*4],tag[N*4];
void pushup(int rt){mn[rt]=min(mn[ls],mn[rs]);}
void build(int rt,int l,int r)
{
    mn[rt]=tag[rt]=0;if (l==r) return;
    int mid=(l+r)/2;build(ls,l,mid);build(rs,mid+1,r);pushup(rt);
}
void pushdown(int rt){int t=tag[rt];if (t){mn[ls]+=t;tag[ls]+=t;mn[rs]+=t;tag[rs]+=t;tag[rt]=0;}}
void add(int rt,int l,int r,int L,int R,int x)
{
    if (L>R || l>R || L>r) return;
    if (L<=l && r<=R) {tag[rt]+=x;mn[rt]+=x;return;}
    pushdown(rt);
    int mid=(l+r)/2;
    if (mid>=L) add(ls,l,mid,L,R,x);
    if (mid<R) add(rs,mid+1,r,L,R,x);
    pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
    if (L>R || l>R || L>r) return 1e18;
    if (L<=l && r<=R) return mn[rt];
    pushdown(rt);
    int ret=1e18,mid=(l+r)/2;
    if (mid>=L) ret=min(ret,query(ls,l,mid,L,R));
    if (mid<R) ret=min(ret,query(rs,mid+1,r,L,R));
    return ret;
}
void DOIT()
{
    rd(n);rd(m);ans=0;
    for (int i=1;i<=n;i++) rd(a[i]),p[i]=i,c[i]=a[i];
    for (int i=1;i<=m;i++) rd(b[i]);
    sort(b+1,b+m+1);sort(p+1,p+n+1,cmp);sort(a+1,a+n+1);
    build(1,1,n+1);
    for (int i=1;i<=n;i++)
    {
        c[i]=lower_bound(a+1,a+n+1,c[i])-a;
        ans+=query(1,1,n+1,c[i],c[i]);
        add(1,1,n+1,1,c[i]-1,1);
    }
    build(1,1,n+1);
    for (int i=1;i<=n;i++) add(1,1,n+1,i+1,n+1,1);
    int i=1,j=1;
    for (int k=1;k<=m;k++)
    {
        while (b[k]>=a[i] && i<=n) add(1,1,n+1,p[i]+1,n+1,-1),i++;
        while (b[k]>a[j] && j<=n) add(1,1,n+1,1,p[j],1),j++;
        ans+=query(1,1,n+1,1,n+1);
    }
    cout<<ans<<"\n";
    // b   


}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
    
    
}
/*

*/