#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
const int N=2e6+2;
vector<int> lb[N],bh[N];
ll ans;
int bel[N],ed[N],f[N],nf[N],app[N],fir[N],nxt[N],lj[N];
int n,c,fh,i,j,k,t,x,y,m,bs,q,tp,cnt,cur,atp,ld;
bool av[N],ned[N];
struct Q
{
    int bu,bv,u,v;
    Q(int a=0,int b=0):bu(bel[a]),bv(bel[b]),u(a),v(b){}
    bool operator<(const Q &o) const {return (bu<o.bu)||(bu==o.bu)&&(bv<o.bv);}
};
Q st[N];
inline void add(int x,int y)
{
    lj[++bs]=y;
    nxt[bs]=fir[x];
    fir[x]=bs;
    lj[++bs]=x;
    nxt[bs]=fir[y];
    fir[y]=bs;
}
inline void read(int &x)
{
    c=getchar();fh=1;
    while ((c<48)||(c>57))
    {
        if (c=='-') {c=getchar();fh=-1;break;}
        c=getchar();
    }
    x=c^48;c=getchar();
    while ((c>=48)&&(c<=57))
    {
        x=x*10+(c^48);
        c=getchar();
    }
    x*=fh;
}
void dfs1(int x,int y)
{
    ed[x]=cnt;f[x]=y;
    for (int i=0;i<lb[x].size();i++) if (!ed[lb[x][i]]) dfs1(lb[x][i],y^1); else
    {
        if (y==f[lb[x][i]]) {av[cur]=0;return;}
    }
}
void dfs2(int x,int y)
{
    //printf("dfs2 %d %d\n",x,y);
    ned[x]=1;nf[x]=y;
    for (int i=fir[x];i;i=nxt[i]) if (!ned[lj[i]]) dfs2(lj[i],y^1); else
    {
        if (y==nf[lj[i]]) {av[cur]=0;return;}
    }
}
int main()
{
    //freopen("a.in","r",stdin);
    read(n);read(m);read(q);
    for (i=1;i<=n;i++) {read(bel[i]);bh[bel[i]].push_back(i);}
    while (m--)
    {
        read(x);read(y);if (bel[x]!=bel[y])
        {
            if (bel[x]>bel[y]) swap(x,y);
            st[++tp]=Q(x,y);
        } else lb[x].push_back(y),lb[y].push_back(x);
    }
    for (i=1;i<=q;i++) av[i]=1;ld=n;
    for (i=1;i<=q;i++)
    {
        cur=i;
        for (j=0;(j<bh[i].size())&&(av[cur]);j++) if (!ed[bh[i][j]]) {++cnt;dfs1(bh[i][j],0);}
    }cnt=0;
    for (i=1;i<=q;i++) if (!av[i]) ++cnt;
    ans=(ll)(q-cnt)*(q-cnt-1)>>1;
    sort(st+1,st+tp+1);
    for (i=1;i<=tp;i=j+1)
    {
        j=i;
        while ((j<tp)&&(st[j+1].bu==st[i].bu)&&(st[j+1].bv==st[i].bv)) ++j;
        if (!(av[st[i].bv]&&av[st[i].bu])) continue;
        atp=0;
        for (k=i;k<=j;k++)
        {
            //if ((st[k].bu==2)&&(st[k].bv==3)) printf("%d %d %d %d %d\n",st[k].u,st[k].v,(int)f[st[k].u]==f[st[k].v],ed[st[k].u],ed[st[k].v]);
            if (f[st[k].u]!=f[st[k].v])
            {
                add(ed[st[k].u],++ld);
                add(ld,ed[st[k].v]);
            } else add(ed[st[k].u],ed[st[k].v]);
            if (!ned[ed[st[k].u]]) app[++atp]=ed[st[k].u],ned[ed[st[k].u]]=1;
            if (!ned[ed[st[k].v]]) app[++atp]=ed[st[k].v],ned[ed[st[k].v]]=1;
        }
        for (k=1;k<=atp;k++) ned[app[k]]=0;
        av[cur=i+q]=1;
        for (k=1;(k<=atp)&&(av[cur]);k++) if (!ned[app[k]]) dfs2(app[k],0);
        if (!av[cur]) --ans;
        //printf("%d:%d %d\n",(int)av[cur],st[i].bu,st[i].bv);
        for (k=1;k<=atp;k++) fir[app[k]]=0,ned[app[k]]=0;bs=0;
    }
    printf("%lld",ans);
}