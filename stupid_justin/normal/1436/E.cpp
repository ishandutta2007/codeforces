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
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
void gmin(int &x,int y){x=min(x,y);}
int n,ans;
int a[N],b[N];
int mn[N<<2],la[N<<2];
void pushup(int rt){mn[rt]=min(mn[ls],mn[rs]);}

void build(int rt,int l,int r)
{
    la[rt]=0;if (l==r){mn[rt]=l-(l&1);return;}
    int mid=(l+r)>>1;build(ls,l,mid);build(rs,mid+1,r);pushup(rt);
}
void update(int rt,int l,int r,int p,int x)
{
    if (l==r) {mn[rt]=x;return;}
    int mid=(l+r)>>1;
    if (p<=mid) update(ls,l,mid,p,x);
    if (p>mid) update(rs,mid+1,r,p,x);
    pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
    if (L>R) return inf;if (L<=l && r<=R) return mn[rt];
    int mid=(l+r)/2,ret=inf;
    if (L<=mid) gmin(ret,query(ls,l,mid,L,R));
    if (R>mid) gmin(ret,query(rs,mid+1,r,L,R));
    return ret;
}
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=1) b[1]=1;
        if (a[i]>1 && query(1,1,n,1,a[i]-1)>la[a[i]]) b[a[i]]=1;
        la[a[i]]=i;update(1,1,n,a[i],i);
    }
    for (int i=2;i<=n+1;i++) if (query(1,1,n,1,i-1)>la[i]) b[i]=1;
    for (int i=1;i<=n+2;i++) if (!b[i]) {ans=i;break;}
    cout<<ans<<endl;
}