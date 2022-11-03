/*
ID: Sfiction
OJ: CF
PROB: 337D
*/
#include <cstdio>
#include <cstring>
const int MAXN=100000,g=-1<<30;
struct Node
{
    //This settlement was affected or not
    int aff;
    //the farthest aff in/not in this subtree
    int down,up;
    int down2;
    int nex;
}tree[MAXN+1];
struct Edge
{
    int v;
    int nex;
}edge[MAXN<<1];
char vis[MAXN+1];
int n,d,ans;
void Init()
{
    int m,t;
    int u,v;
    scanf("%d%d%d",&n,&m,&d);
    for (;m;--m)
    {
        scanf("%d",&t);
        tree[t].aff=1;
    }
    t=0;
    for (m=1;m<n;++m)
    {
        scanf("%d%d",&u,&v);
        ++t;
        edge[t].nex=tree[u].nex;
        edge[t].v=v;
        tree[u].nex=t;
        ++t;
        edge[t].nex=tree[v].nex;
        edge[t].v=u;
        tree[v].nex=t;
    }
}
void TreeIn(int x)
{
    int i,j;
    vis[x]=1;
    if (tree[x].aff) tree[x].down=0;
    else tree[x].down=g;
    tree[x].down2=g;
    for (i=tree[x].nex;i;i=edge[i].nex)
        if (!vis[j=edge[i].v])
        {
            TreeIn(j);
            if (tree[j].down+1>=tree[x].down)
            {
                tree[x].down2=tree[x].down;
                tree[x].down=tree[j].down+1;
            }
            else if (tree[j].down>=tree[x].down2) tree[x].down2=tree[j].down+1;
        }
}
void TreeOut(int x)
{
    int i,j;
    vis[x]=1;
    for (i=tree[x].nex;i;i=edge[i].nex)
        if (!vis[j=edge[i].v])
        {
            if (tree[j].down+1!=tree[x].down) tree[j].up=tree[x].down+1;
            else tree[j].up=tree[x].down2+1;
            if (tree[x].up>=tree[j].up) tree[j].up=tree[x].up+1;
            TreeOut(j);
        }
    if (tree[x].down<=d&&tree[x].up<=d) ++ans;
}
int main()
{
    Init();
    memset(vis+1,0,n);
    TreeIn(1);
    memset(vis+1,0,n);
    ans=0;
    tree[1].up=g;
    TreeOut(1);
    printf("%d",ans);
    return 0;
}