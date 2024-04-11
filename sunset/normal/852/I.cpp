#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int Size = 200010;
#define P 20
int n, m, a[Size], fst[Size], vb[Size], nxt[Size], as[Size], M=0, fa[Size];
void ad_de(int a,int b) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
int cc=0,st[Size],ed[Size],dfx[Size],ib[Size];

int read()
{
    int x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x;
}

void dfs(int x)
{
    st[x]=++cc; dfx[cc]=x;
    for(int e=fst[x];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[x]) continue;
        fa[b]=x; dfs(b);
    }
    ed[x]=++cc; dfx[cc]=x;
}
typedef pair<int,int> pii;
int cc_=0,app[Size],dep[Size],lo2[Size];
pii pp[Size],minn[Size][P];
void dfs_(int x)
{
    ++cc_; app[x]=cc_; pp[cc_]=pii(dep[x],x);
    for(int e=fst[x];e;e=nxt[e])
    {
        int b=vb[e]; if(b==fa[x]) continue;
        dep[b]=dep[x]+1; dfs_(b);
        pp[++cc_]=pii(dep[x],x);
    }
}
void build()
{
    for(int i=1;i<=cc_;i++) minn[i][0]=pp[i];
    for(int i=1;i<=cc_;i++)
    {
        int g=0;
        while((1<<g)<=i) ++g;
        lo2[i]=g-1;
    }
    for(int p=1;p<P;p++)
    {
        for(int i=1;i<=cc_;i++)
        {
            if(i+(1<<p)-1>cc_) break;
            minn[i][p]=min(minn[i][p-1],minn[i+(1<<(p-1))][p-1]);
        }
    }
}
int lca(int a,int b)
{
    a=app[a]; b=app[b];
    if(a>b) swap(a,b);
    int l2=lo2[b-a+1];
    return min(minn[a][l2],minn[b-(1<<l2)+1][l2]).second;
}
int bs,qn=0;
struct query {int l,r,m,id;} qs[Size];
bool operator < (query a,query b)
{
    if(a.l/bs!=b.l/bs) return a.l/bs<b.l/bs;
    else return (a.l/bs) & 1 ? a.r<b.r : a.r > b.r;
}
#define Addq(l_,r_,m_,id_) ++qn, qs[qn].l=l_, qs[qn].r=r_, qs[qn].m=m_, qs[qn].id=id_;
long long cov[Size],coa[2][Size];
long long ans=0,anss[Size];
void edt(int p,int k)
{
    ans-=coa[0][a[p]]*coa[1][a[p]];
    coa[ib[p]][a[p]]-=cov[p]&1;
    cov[p]+=k;
    coa[ib[p]][a[p]]+=cov[p]&1;
    ans+=coa[0][a[p]]*coa[1][a[p]];
}
int main()
{
    n = read(); bs=sqrt(n)+1;
    for(int i=1;i<=n;i++) ib[i] = read();
    for(int i=1;i<=n;i++) a[i] = read(), as[i]=a[i];
    sort(as+1,as+1+n); int nn=unique(as+1,as+1+n)-as-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(as+1,as+1+nn,a[i])-as;
    for(int i=1;i<n;i++)
    {
        int a,b;
        a = read(); b = read();
        adde(a,b);
    }
    dfs(1); dfs_(1); build();
    m = read();
    for(int i=1;i<=m;i++)
    {
        int a,b,p;
        a = read(); b = read();
        p=lca(a,b);
        if(st[a]>st[b]) swap(a,b);
        if(p==a) Addq(st[a],st[b],0,i)
        else Addq(ed[a],st[b],p,i)
    }
    sort(qs+1,qs+1+qn);
    int l=1,r=0;
    for(int i=1;i<=qn;i++)
    {
        int ql=qs[i].l,qr=qs[i].r;
        while(l<ql) edt(dfx[l++],-1);
        while(l>ql) edt(dfx[--l],1);
        while(r>qr) edt(dfx[r--],-1);
        while(r<qr) edt(dfx[++r],1);
        if(qs[i].m) edt(qs[i].m,1);
        anss[qs[i].id]=ans;
        if(qs[i].m) edt(qs[i].m,-1);
    }
    for(int i=1;i<=m;i++) printf("%lld\n",anss[i]);
}