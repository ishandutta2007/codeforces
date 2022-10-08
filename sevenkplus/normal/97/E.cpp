#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
struct E{int ad,id,ne;}e[N*4];
int n,m,q,u[N],v[N],w[N],h1[N],h2[N],de[N],fa[N],f[N],p0[N],p1[N];bool o[N];
void add(int*he,int x,int y,int d)
{
    static int t=0;
    ++t,e[t].ne=he[x],he[x]=t,e[t].ad=y,e[t].id=d;
}
int ff(int*f,int x)
{
    if(f[x]==x)return x;
    else return f[x]=ff(f,f[x]);
}
void ff1(int x)
{
    p0[x]=p1[x]=x;
    for(int p=h1[x];p;p=e[p].ne)
    {
        int y=e[p].ad;
        if(!de[y])
        {
            fa[y]=x,de[y]=de[x]+1,ff1(y),p1[y]=x;
            if(ff(p0,x)==ff(p0,y))o[x]|=o[y];
        }else
        if(de[y]+1<de[x])
        {
            int z=ff(p0,x);
            while(de[z]>de[y]+1)
                p0[z]=fa[z],z=ff(p0,z);
            if((de[x]-de[y])%2==0)o[x]=1;
        }
    }
    for(int p=h2[x];p;p=e[p].ne)
        if(de[e[p].ad])w[e[p].id]=ff(p1,e[p].ad);
}
void ff2(int x)
{
    if(o[ff(p0,x)])f[x]++;
    for(int i=h1[x];i;i=e[i].ne)
    {
        int y=e[i].ad;
        if(de[y]==de[x]+1)
        {
            if(ff(p0,x)==ff(p0,y))o[y]|=o[x];
            f[y]=f[x],ff2(y);
        }
    }
}
bool chk(int u,int v,int w)
{
    if(ff(p1,u)!=ff(p1,v))return 0;
    if((de[u]-de[v])%2)return 1;
    return f[u]+f[v]-f[w]*2>0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),
        add(h1,x,y,i),add(h1,y,x,i);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d",u+i,v+i),
        add(h2,u[i],v[i],i),add(h2,v[i],u[i],i);
    for(int i=1;i<=n;i++)
        if(!de[i])de[i]=1,ff1(i),ff2(i);
    for(int i=1;i<=q;i++)
        puts(chk(u[i],v[i],w[i])?"Yes":"No");
    return 0;
}