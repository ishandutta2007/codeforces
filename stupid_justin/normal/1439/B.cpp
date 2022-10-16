#include<bits/stdc++.h>
#define ull unsigned long long
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
const int M=1000;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,k,sz;
vector<int> G[N];
int d[N],mn[N*4];
int P[N],H[N],tot;
int b1[N][N/8192],cnt;
ull b2[N][128];
void add(int u,int v)
{
    if (!b1[u][v/8192]) b1[u][v/8192]=++cnt;
    b2[b1[u][v/8192]][v/64%128]|=1ull<<(v%64);
}
bool chk(int u,int v)
{
    if (!b1[u][v/8192]) return 0;
    return b2[b1[u][v/8192]][v/64%128]>>(v%64)&1;
}
void pushup(int rt){if (d[mn[rs]]<d[mn[ls]]) mn[rt]=mn[rs];else mn[rt]=mn[ls];}
void build(int rt,int l,int r)
{
    if (l==r){mn[rt]=l;return;}
    int mid=(l+r)/2;build(ls,l,mid);build(rs,mid+1,r);pushup(rt);
}
void update(int rt,int l,int r,int p,int x)
{
    if (l==p && p==r) {d[p]+=x;return;}
    int mid=(l+r)/2;
    if (p<=mid) update(ls,l,mid,p,x);
    if (p>mid) update(rs,mid+1,r,p,x);
    pushup(rt);
}
void DOIT()
{
    rd(n);rd(m);rd(k);cnt=0;
    for (int i=1;i<=n;i++) G[i].clear(),d[i]=0;
    for (int i=1;i<=n;i++) memset(b1[i],0,sizeof(b1[i])),memset(b2[i],0,sizeof(b2[i]));
    for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[x].push_back(y),G[y].push_back(x),add(x,y),add(y,x);
    for (int i=1;i<=n;i++) d[i]=G[i].size();sz=n;build(1,1,n);
    while (sz>k)
    {
        int u=mn[1];
        if (d[u]>=k) {cout<<1<<" "<<sz<<"\n";for (int i=1;i<=n;i++) if (d[i]<n+5) cout<<i<<" ";cout<<"\n";return;}
        for (int v:G[u]) update(1,1,n,v,-1);
        update(1,1,n,u,3*n);sz--;
    }

    for (int i=1;i<=n;i++) d[i]=G[i].size();sz=n;build(1,1,n);
    while (sz>=k)
    {
        int u=mn[1];
        if (d[u]==k-1) 
        {
            tot=1;P[1]=u;for (int v:G[u]) if (d[v]<n+5) P[++tot]=v;
            bool flag=1;
            for (int i=1;i<=tot;i++) {if (!flag) break;for (int j=i+1;j<=tot;j++) if (!chk(P[i],P[j])) {flag=0;break;}}
            if (flag){cout<<2<<"\n";for (int i=1;i<=k;i++) cout<<P[i]<<" ";cout<<"\n";return;}
        }
        for (int v:G[u]) update(1,1,n,v,-1);
        update(1,1,n,u,inf);sz--;
    }

    puts("-1");


}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}