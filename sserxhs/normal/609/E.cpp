#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=2e5+2,M=4e5+20;
typedef long long ll;
int lj[M],len[M],nxt[M],fir[N],f[N],fa[N],lb[N][4],hc[N],st[N][18],dy[N];
int dep[N],top[N],dfn[N],nfd[N],fx[N],ans[N],siz[N],lf[N];
int n,m,i,j,x,y,z,c,bs;
ll tot;
inline void read(int &x)
{
    c=getchar();
    while ((c<48)||(c>57)) c=getchar();
    x=c^48;c=getchar();
    while ((c>=48)&&(c<=57))
    {
        x=x*10+(c^48);
        c=getchar();
    }
}
void qs(int l,int r)
{
    int i=l,j=r,m=lb[l+r>>1][0];
    while (i<=j)
    {
        while (lb[i][0]<m) ++i;
        while (lb[j][0]>m) --j;
        if (i<=j)
        {
            swap(lb[i][0],lb[j][0]);
            swap(lb[i][1],lb[j][1]);
            swap(lb[i][2],lb[j][2]);
            swap(lb[i++][3],lb[j--][3]);
        }
    }
    if (i<r) qs(i,r);
    if (l<j) qs(l,j);
}
inline void add(int x,int y,int z)
{
    lj[++bs]=y;
    len[bs]=z;
    nxt[bs]=fir[x];
    fir[x]=bs;
    lj[++bs]=x;
    len[bs]=z;
    nxt[bs]=fir[y];
    fir[y]=bs;
}
int getfa(int x)
{
    if (fa[x]==x) return x;
    return fa[x]=getfa(fa[x]); 
}
void dfs1(int x)
{
    siz[x]=1;
    int i;
    for (i=fir[x];i;i=nxt[i]) if (f[x]!=lj[i])
    {
        dep[lj[i]]=dep[f[lj[i]]=x]+1;
        lf[lj[i]]=len[i];
        dfs1(lj[i]);
        siz[x]+=siz[lj[i]];
        if (siz[hc[x]]<siz[lj[i]]) hc[x]=lj[i];
    }
}
void dfs2(int x)
{
    nfd[dfn[x]=++bs]=x;
    if (hc[x])
    {
        int i;
        top[hc[x]]=top[x];
        dfs2(hc[x]);
        for (i=fir[x];i;i=nxt[i]) if ((lj[i]!=f[x])&&(lj[i]!=hc[x])) dfs2(top[lj[i]]=lj[i]);
    }
}
inline int rmq(int x,int y)
{
    int z=dy[y-x+1];
    return max(st[x][z],st[y-(1<<z)+1][z]);
}
inline int sol(int x,int y)
{
    int r=0;
    while (top[x]!=top[y])
    {
        if (dep[top[x]]<dep[top[y]]) swap(x,y);
        r=max(r,rmq(dfn[top[x]],dfn[x]));
        x=f[top[x]];
    }
    if (x==y) return r;
    if (dep[x]<dep[y]) return max(r,rmq(dfn[x]+1,dfn[y]));
    return max(r,rmq(dfn[y]+1,dfn[x]));
}
int main()
{
    read(n);read(m);
    for (i=1;i<=m;i++)
    {
        read(lb[i][1]);read(lb[i][2]);read(lb[i][0]);lb[i][3]=i;
    }
    qs(1,m);
    for (i=1;i<=m;i++) fx[lb[i][3]]=i;
    for (i=1;i<=n;i++) fa[i]=i;
    for (i=1;i<=m;i++) if (getfa(lb[i][1])!=getfa(lb[i][2]))
    {
        fa[fa[lb[i][1]]]=fa[lb[i][2]];
        add(lb[i][1],lb[i][2],lb[i][0]);
        tot+=lb[i][0];
        lb[i][0]=0;
    }
    bs=0;
    dfs1(dep[1]=1);
    dfs2(top[1]=1);
    for (i=2;i<=n;i++) st[i][0]=lf[nfd[i]];
    for (i=2;i<=n;i++) dy[i]=dy[i>>1]+1;x=1;
    for (j=1;j<=17;j++,x<<=1) for (i=2;i<=n;i++)
    {
        st[i][j]=st[i][j-1];
        if (x+i<=n) st[i][j]=max(st[i][j],st[i+x][j-1]);
    }
    for (i=1;i<=m;i++)if (lb[i][0]) ans[lb[i][3]]=lb[i][0]-sol(lb[i][1],lb[i][2]);
    for (i=1;i<=m;i++) printf("%lld\n",tot+ans[i]);
}