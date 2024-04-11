#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define endl "\n"
using namespace std;
const int N=6e5+5;
const int M=605;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}

struct FENKUAI
{
    int n,k,SZ,a[N],cnt[N],L[M],R[M];
    int pos(int x){return (x-1)/SZ+1;}
    void Init(int m){n=m;SZ=sqrt(n);k=pos(n);for (int i=1;i<=k;i++) L[i]=R[i-1]+1,R[i]=i*SZ;R[k]=n;}
    void add(int x){int p=pos(x);cnt[p]-=a[x];a[x]^=1;cnt[p]+=a[x];}
    int query(int l,int r){for (int i=pos(l);i<=pos(r);i++) if (cnt[i]) for (int j=max(L[i],l);j<=min(r,R[i]);j++) if (a[j]) return j;return -1;}
}K;
int n,q,idx;
int a[N],E[N],p1[N],p2[N],ans[N];
int anc[20][N],dep[N];
int lca(int u,int v)
{
    if (dep[u]<dep[v]) swap(u,v);
    for (int i=19;i>=0;i--) if (dep[u]-(1<<i)>=dep[v]) u=anc[i][u];if (u==v) return u;
    for (int i=19;i>=0;i--) if (anc[i][u]!=anc[i][v]) u=anc[i][u],v=anc[i][v];return anc[0][u];
}
vector<int> T[N];
void dfs(int u,int fa){dep[u]=dep[fa]+1;anc[0][u]=fa;E[++idx]=a[u];p1[u]=idx;for (int v:T[u]) if (v!=fa) dfs(v,u);E[++idx]=a[u];p2[u]=idx;}
const int SZ=800;
#define pos(x) x/SZ
struct query{int l,r,L,R,t,id;}Q[N];
bool cmp(query x,query y){if (x.l/SZ!=y.l/SZ) return x.l<y.l;return (x.l/SZ)&1?x.r<y.r:x.r>y.r;}
signed main()
{
    rd(n);rd(q);for (int i=1;i<=n;i++) rd(a[i]);K.Init(n);
    for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
    dfs(1,0);for (int k=1;k<=19;k++) for (int i=1;i<=n;i++) anc[k][i]=anc[k-1][anc[k-1][i]];
    for (int i=1,x,y,l,r;i<=q;i++) 
    {
        rd(x),rd(y),rd(l),rd(r);int L=lca(x,y);
        if (L==x || L==y) 
        {
            if (p1[x]>p1[y]) swap(x,y);
            Q[i]={p1[x],p1[y],l,r,0,i};
        }else 
        {
            if (p2[x]>p1[y]) swap(x,y);
            Q[i]={p2[x],p1[y],l,r,L,i};
        }
    }
    for (int i=1;i<=q;i++) if (Q[i].l>Q[i].r) swap(Q[i].l,Q[i].r);
    stable_sort(Q+1,Q+q+1,cmp);
    int l=0,r=0;
    for (int i=1;i<=q;i++)
    {
        while (l>Q[i].l) K.add(E[--l]);
        while (l<Q[i].l) K.add(E[l++]);
        while (r>Q[i].r) K.add(E[r--]);
        while (r<Q[i].r) K.add(E[++r]);
        if (Q[i].t) K.add(a[Q[i].t]);
        ans[Q[i].id]=K.query(Q[i].L,Q[i].R);
        if (Q[i].t) K.add(a[Q[i].t]);
    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";

}
/*

*/