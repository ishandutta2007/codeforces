#include<cstdio>

using namespace std;

struct lhy{
    int y,next;
    char kind;
}edge[16000000];

char a[2010][2010];
int du[2001*2001],son[2001*2001],q[2001*2001],b[2001*2001];
int n,m,ToT,tot,sum,l,h,v;

inline void add(int x,int y,int kind)
{
    du[x]++;edge[++tot].y=y;edge[tot].next=son[x];edge[tot].kind=kind;son[x]=tot;
}

inline int num(int x,int y)
{
    return m*(x-1)+y;
}

inline int X(int v)
{
    return (v-1)/m+1;
}

inline int Y(int v)
{
    return (v-1)%m+1;
}

int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.')
            {
                if(a[i+1][j]=='.')add(num(i,j),num(i+1,j),1);
                if(a[i-1][j]=='.')add(num(i,j),num(i-1,j),2);
                if(a[i][j+1]=='.')add(num(i,j),num(i,j+1),3);
                if(a[i][j-1]=='.')add(num(i,j),num(i,j-1),4);
            }
    sum=n*m;
    for(int i=1;i<=sum;i++)
        if(du[i]==1)q[++l]=i;
    while(h<l)
    {
        v=q[++h];
        if(b[v])continue;
        for(int i=son[v];i;i=edge[i].next)
            if(!b[edge[i].y])
            {
                if(edge[i].kind==1)a[X(v)][Y(v)]='^',a[X(v)+1][Y(v)]='v';
                if(edge[i].kind==2)a[X(v)][Y(v)]='v',a[X(v)-1][Y(v)]='^';
                if(edge[i].kind==3)a[X(v)][Y(v)]='<',a[X(v)][Y(v)+1]='>';
                if(edge[i].kind==4)a[X(v)][Y(v)]='>',a[X(v)][Y(v)-1]='<';
                b[edge[i].y]=1;
                for(int j=son[edge[i].y];j;j=edge[j].next)
                {
                    du[edge[j].y]--;
                    if(!b[edge[j].y]&&du[edge[j].y]==1)q[++l]=edge[j].y;
                }
            }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.')return puts("Not unique"),0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) 
            putchar(a[i][j]);
        putchar('\n');
    }
}