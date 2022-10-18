#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int S=5e5+2,N=1e6+2;
int c[N][27],dep[N],f[N],t[N],zd[N],lj[N],nxt[N],fir[N],len[N],siz1[N],siz2[N],fa[N],s[S];
int top[N],hc[N],dfn[N],dy[N],st[N],a[N];
int n,m,mm,q,i,j,x,ds=1,point=1,ad,r,edge,remain,bs,fbs,cc,tp,ance;
ll ans;
inline void read(int &x)
{
    cc=getchar();
    while ((cc<48)||(cc>57)) cc=getchar();
    x=cc^48;cc=getchar();
    while ((cc>=48)&&(cc<=57))
    {
        x=x*10+(cc^48);
        cc=getchar();
    }
}
inline void xadd(int x,int y)
{
    lj[++bs]=y;
    nxt[bs]=fir[x];
    fir[x]=bs;
}
inline void add(int x,int y)
{
    lj[++fbs]=y;
    nxt[fbs]=fir[x];
    fir[x]=fbs;
}
inline void add(int x,int y,int z)
{
    lj[++fbs]=y;
    len[bs]=z;
    nxt[fbs]=fir[x];
    fir[x]=bs;
}
inline void add(int a,int b,int cc,int d)
{
    c[a][s[cc]]=++bs;
    f[bs]=cc;t[bs]=d;
    zd[bs]=b;
}
void dfs1(int x)
{
    siz1[x]=1;
    if (!fir[x]) {dy[n-dep[x]+1]=x;return;}
    int i;
    for (i=fir[x];i;i=nxt[i])
    {
        dep[lj[i]]=dep[f[lj[i]]=x]+len[i];
        dfs1(lj[i]);
        siz1[x]+=siz1[lj[i]];
        if (siz1[lj[i]]>siz1[hc[x]]) hc[x]=lj[i];
    }
}
void dfs2(int x)
{
    dfn[x]=++bs;
    if (hc[x])
    {
        top[hc[x]]=top[x];
        dfs2(hc[x]);
        int i;
        for (i=fir[x];i;i=nxt[i]) if (lj[i]!=hc[x]) dfs2(top[lj[i]]=lj[i]);
    }
}
bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
inline int lca(register int x,register int y)
{
    while (top[x]!=top[y]) if (dep[top[x]]<dep[top[y]]) y=f[top[y]]; else x=f[top[x]];
    if (dep[x]<dep[y]) return x; return y;
}
inline void ins(int x)
{
    if (!tp) {st[tp=1]=x;return;}
    ance=lca(st[tp],x);
    while ((tp>1)&&(dep[st[tp-1]]>dep[ance]))
    {
        xadd(st[tp-1],st[tp]);
        --tp;
    }
    if (dep[st[tp]]>dep[ance]) xadd(ance,st[tp--]);
    if ((!tp)||(st[tp]!=ance)) st[++tp]=ance;
    st[++tp]=x;
}
void dfs3(int x)
{
    int i;ans+=(ll)siz1[x]*siz2[x]*(dep[x]-1);
    for (i=fir[x];i;i=nxt[i])
    {
        dfs3(lj[i]);ans+=((ll)siz1[x]*siz2[lj[i]]+(ll)siz2[x]*siz1[lj[i]])*dep[x];
        siz1[x]+=siz1[lj[i]];
        siz2[x]+=siz2[lj[i]];
    }
   // printf("%d %d %d\n",siz1[x],siz2[x],dep[x]);
}
void dfs4(int x)
{
    int i;
    for (i=fir[x];i;i=nxt[i]) dfs4(lj[i]);
    siz1[x]=siz2[x]=fir[x]=0;
}
int main()
{
    read(n);read(q);
    cc=getchar();
    while ((cc<'a')||(cc>'z')) cc=getchar();
    s[1]=cc-97;
    for (i=2;i<=n;i++) s[i]=getchar()-97;fa[1]=1;
    s[++n]=26;
    for (i=1;i<=n;i++)
    {
        ad=0;++remain;
        while (remain)
        {
            if (r==0) edge=i;
            if ((j=c[point][s[edge]])==0)
            {
                fa[ad]=point;
                fa[++ds]=1;
                add(ad=point,ds,edge,n);
                add(point,s[edge]);
            }
            else
            {
                if ((t[j]!=n)&&(t[j]-f[j]+1<=r))
                {
                    r-=t[j]-f[j]+1;
                    edge+=t[j]-f[j]+1;
                    point=zd[j];
                    continue;
                }
                if (s[i]==s[f[j]+r])
                {
                    ++r;fa[ad]=point;break;
                }
                fa[fa[ad]=++ds]=1;add(ad=ds,zd[j],f[j]+r,t[j]);
                add(ds,s[f[j]+r]);zd[j]=ds;t[j]=f[j]+r-1;
                add(ds,s[i]);fa[++ds]=1;add(ds-1,ds,i,n);
            }
            --remain;
            if ((r)&&(point==1))
            {
                --r;
                edge=i-remain+1;
            } else point=fa[point];
        }
    }//ukksam
    for (i=1;i<=ds;i++) for (j=fir[i];j;j=nxt[j])
    {
        x=c[i][lj[j]];
        lj[j]=zd[x];
        len[j]=t[x]-f[x]+1;
    }
    memset(f+1,0,bs<<2);bs=0;
    dfs1(1);dfs2(top[1]=1);
    memset(siz1+1,0,ds<<2);
    memset(fir+1,0,ds<<2);bs=0;
    while (q--)
    {
        read(m);ans=bs=0;read(mm);
        for (i=1;i<=m;i++)
        {
            read(a[i]);siz1[a[i]=dy[a[i]]]=1;
        }
        for (i=m+1;i<=m+mm;i++)
        {
            read(a[i]);siz2[a[i]=dy[a[i]]]=1;
        }m+=mm;
        sort(a+1,a+m+1,cmp);if (a[1]!=1) ins(1);
        for (i=1;i<=m;i++) if ((i==1)||(a[i]!=a[i-1])) ins(a[i]);
        while (--tp) xadd(st[tp],st[tp+1]);
        dfs3(1);dfs4(1);printf("%lld\n",ans);
    }
}