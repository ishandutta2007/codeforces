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
void gmax(int &x,int y){x=max(x,y);}
int n,ans;
int a[N],p[N],L[N],R[N];
int mx[N<<2],tag[N<<2];
void pushup(int rt){mx[rt]=max(mx[ls],mx[rs])+tag[rt];}

void build(int rt,int l,int r)
{
    tag[rt]=0;if (l==r){mx[rt]=l-(l&1);return;}
    int mid=(l+r)>>1;build(ls,l,mid);build(rs,mid+1,r);pushup(rt);
}

void update(int rt,int l,int r,int L,int R,int x)
{
    if (L<=l && r<=R) {tag[rt]+=x;mx[rt]+=x;return;}
    int mid=(l+r)>>1;if (L<=mid) update(ls,l,mid,L,R,x);if (R>mid) update(rs,mid+1,r,L,R,x);pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
    if (L>R) return 0;if (L<=l && r<=R) return mx[rt];
    int mid=(l+r)/2,ret=0;if (L<=mid) gmax(ret,query(ls,l,mid,L,R));if (R>mid) gmax(ret,query(rs,mid+1,r,L,R));return ret+tag[rt];
}
void DOIT()
{
    ans=0;rd(n);for (int i=1;i<=n;i++) rd(a[i]),p[a[i]]=i;build(1,1,n);
    L[n+1]=n+1;R[0]=0;
	for (int i=n;i>=1;i--) L[i]=min(L[i+1],p[i]);
	for (int i=1;i<=n;i++) R[i]=max(R[i-1],p[i]);
    for (int i=1;i<n;i++)
    {
        int t=p[i];
        update(1,1,n,t,t,t&1?1:-1);if (t!=1) update(1,1,n,1,t-1,1);if (t!=n) update(1,1,n,t+1,n,-1);
        ans=max(ans,query(1,1,n,L[i+1],R[i]));
    }
    cout<<ans<<endl;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/