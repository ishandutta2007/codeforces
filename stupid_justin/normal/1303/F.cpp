#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=305;
const int M=4e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int n,m,q,cnt;
int ans[M];
struct DSU
{
    int FA[M];
    void init(int n){for (int i=1;i<=n;i++) FA[i]=0;}
    int getfa(int x){if (FA[x]==x)return x;return FA[x]=getfa(FA[x]);}
    bool merge(int u,int v){u=getfa(u);v=getfa(v);if (u==v) return 0;FA[u]=v;cnt--;return 1;}
}D;
int id[N][N],tot;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int a[N][N];
void merge(int x,int y){for (int i=0;i<=3;i++) if (a[x][y]==a[x+dx[i]][y+dy[i]])D.merge(id[x][y],id[x+dx[i]][y+dy[i]]);}
struct query{int x,y,col,la;}Q[M];
void solve(int typ)
{
    if (typ==1)
    for (int i=1;i<=q;i++)
    {
        if (Q[i].la==Q[i].col) continue;
        int x=Q[i].x,y=Q[i].y;cnt=1;
        a[x][y]=Q[i].col;id[x][y]=++tot;D.FA[tot]=tot;
        merge(x,y);ans[i]+=cnt;
    } else 
    for (int i=q;i>=1;i--)
    {
        if (Q[i].la==Q[i].col) continue;
        int x=Q[i].x,y=Q[i].y;cnt=1;
        a[x][y]=Q[i].la;id[x][y]=++tot;D.FA[tot]=tot;
        merge(x,y);ans[i]-=cnt;
    }
}
signed main()
{
	rd(n);rd(m);rd(q);
    for (int i=1,x,y,z,w;i<=q;i++)
    {
        rd(x);rd(y);rd(z);
        Q[i]=(query){x,y,z,a[x][y]};a[x][y]=z;
    }
    ans[0]=1;tot=0;
    memset(a,-1,sizeof(a));
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) a[i][j]=0;
    solve(1);memset(D.FA,0,sizeof(D.FA));tot=0;
    //for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) id[i][j]=++tot,D.FA[tot]=tot;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) merge(i,j);
    solve(0);
    for (int i=1;i<=q;i++) ans[i]+=ans[i-1];
    for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
}