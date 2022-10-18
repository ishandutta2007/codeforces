#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pa;
const int N=3e5+2,M=6e5+20;
priority_queue<pa,vector<pa>,greater<pa> > heap;
pa tq,cr;
ll jl[N];
int lj[M],len[M],nxt[M],fir[N],slj[M],slen[M];
int snxt[M],sfir[N],qq[N];
int n,m,q,i,j,x,y,z,c,bs=1,sbs;
bool ed[N];
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
inline void add()
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
inline void sadd(int x,int y,int z)
{
    slj[++sbs]=y;
    slen[sbs]=z;
    snxt[sbs]=sfir[x];
    sfir[x]=sbs;
}
void dfs(int x)
{
    int i;
    for (i=sfir[x];i;i=snxt[i])
    {
        printf("%d ",slen[i]);if (--q==0) return;
        dfs(slj[i]);if (q==0) return;
    }
}
int main()
{
    read(n);read(m);read(q);
    while (m--)
    {
        read(x);read(y);read(z);
        add();
    }
    q=min(q,n-1);
    printf("%d\n",q);
    if (q==0) return 0;
    memset(jl,0x3f,sizeof(jl));
    jl[cr.second=1]=0;heap.push(cr);
    while (!heap.empty())
    {
        tq=heap.top();heap.pop();
        ed[tq.second]=1;
        for (i=fir[tq.second];i;i=nxt[i]) if (jl[lj[i]]>jl[tq.second]+len[i])
        {
            cr.first=jl[cr.second=lj[i]]=jl[tq.second]+len[qq[lj[i]]=i];
            heap.push(cr);
        }
        while ((!heap.empty())&&(ed[heap.top().second])) heap.pop();
    }
    for (i=2;i<=n;i++) sadd(lj[qq[i]^1],i,qq[i]>>1);
    dfs(1);
}