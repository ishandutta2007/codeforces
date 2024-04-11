#include<stdio.h>
#include<algorithm>
#include<cstring>
#define MAXN 410000
using namespace std;
char pans[MAXN];
long head[MAXN],p[MAXN*2],next[MAXN*2],w[MAXN*2],k;
bool choose[MAXN]={false};long fa[MAXN];
long n;long ans=0;long q[MAXN];bool fins[MAXN];long size[MAXN];long dis[MAXN];
long getroot(long x)
{
    q[0]=1;q[1]=x;fa[x]=0;
    for(long i=1;i<=q[0];i++)
    {
        long u=q[i];
        for(long v=head[u];v;v=next[v])
        if(!choose[p[v]]&&fa[u]!=p[v])
        {
            q[++q[0]]=p[v];
            fa[p[v]]=u;
        }
    }
    long root=0;long y=2100000000;
    for(long i=q[0];i>=1;i--)
    {
        long u=q[i];size[u]=1;long max=0;
        for(long v=head[u];v;v=next[v])
        if(!choose[p[v]]&&p[v]!=fa[u])
        {
            if(size[p[v]]>max)max=size[p[v]];
            size[u]+=size[p[v]];
            fa[p[v]]=u;
        }
        if(q[0]-size[u]>max)max=q[0]-size[u];
        if(max<y||root==0)
        {
            root=u;y=max;
        }
    }
    return root;
}
inline void dfs(long x,char nowuse)
{
    long root=getroot(x);
    choose[root]=true;
    pans[root]=nowuse;
    for(long u=head[root];u;u=next[u])
    if(!choose[p[u]])dfs(p[u],nowuse+1);
}
inline void line(long a,long b,long now)
{
    p[now]=b;next[now]=head[a];head[a]=now;
}
inline void read(long &x)
{
    x=0;
    char p=getchar();
    while(!(p<='9'&&p>='0'))p=getchar();
    while(p<='9'&&p>='0')
    {
        x*=10;x+=p-'0';p=getchar();
    }
}
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n-1;i++)
    {
        long a,b;read(a);read(b);
        line(a,b,i*2-1);line(b,a,i*2);
    }
    dfs(1,'A');
    for(long i=1;i<=n;i++)printf("%c ",pans[i]);
    return 0;
}