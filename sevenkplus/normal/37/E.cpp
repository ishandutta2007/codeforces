#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
#define N 55
const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int n,m,T,c[N][N],s[N*N],d[N*N],S;bool a[N][N],v[N][N],v2[N*N];PII E[N*N*4];int EL;
void ff(int x,int y,bool w)
{
    c[x][y]=T,v[x][y]=1,s[T]++;
    for(int i=0;i<4;i++)
    {
        int x0=x+dx[i],y0=y+dy[i];
        if(1<=x0&&x0<=n&&1<=y0&&y0<=m)
            if(!v[x0][y0]&&a[x0][y0]==w)ff(x0,y0,w);
            else if(v[x0][y0]&&a[x0][y0]!=w)E[EL++]=mp(c[x0][y0],T);
    }
}
void gg(int x,int y,bool w)
{
    v[x][y]=1,E[EL++]=mp(x,y);
    for(int i=0;i<4;i++)
    {
        int x0=x+dx[i],y0=y+dy[i];
        if(1<=x0&&x0<=n&&1<=y0&&y0<=m&&!v[x0][y0]&&a[x0][y0]==w)gg(x0,y0,w);
    }
}
bool ff()
{
    T=0,memset(c,0,sizeof c),memset(s,0,sizeof s),memset(v,0,sizeof v),EL=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!v[i][j])++T,ff(i,j,a[i][j]);
    sort(E,E+EL),EL=unique(E,E+EL)-E;
    memset(d,0,sizeof d);
    for(int i=0;i<EL;i++)d[E[i].fi]++,d[E[i].se]++;
    if(T==1){S+=a[1][1];return 0;}S++;
    int S=0,Sx,Sy;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(d[c[i][j]]>S||d[c[i][j]]==S&&!a[Sx][Sy]&&a[i][j])
                S=d[c[i][j]],Sx=i,Sy=j;
    memset(v,0,sizeof v),EL=0;
    gg(Sx,Sy,a[Sx][Sy]);bool w=a[Sx][Sy];
    for(int i=0;i<EL;i++)
        a[E[i].fi][E[i].se]=!w;
    return 1;
}
int he[N*N],ne[N*N*8],ad[N*N*8];
void addE(int x,int y)
{
    static int t=0;
    ++t,ne[t]=he[x],he[x]=t,ad[t]=y,
    ++t,ne[t]=he[y],he[y]=t,ad[t]=x;
}
int q[N*N*2];bool v3[N*N];
void ff2(int x)
{
    memset(v3,0,sizeof v3);
    int le=0,ri=1;v3[x]=1,q[0]=x;
    memset(d,0,sizeof d);
    while(le<ri)
    {
        int x=q[le++];
        for(int p=he[x];p;p=ne[p])
            if(!v3[ad[p]])v3[ad[p]]=1,q[ri++]=ad[p],d[ad[p]]=d[x]+1;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char s[N];
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
            a[i][j]=s[j]=='B';
    }
    T=0,memset(c,0,sizeof c),memset(s,0,sizeof s),memset(v,0,sizeof v),EL=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!v[i][j])++T,ff(i,j,a[i][j]);
    sort(E,E+EL),EL=unique(E,E+EL)-E;
    //memset(d,0,sizeof d);
    //for(int i=0;i<EL;i++)d[E[i].fi]++,d[E[i].se]++;
    for(int i=0;i<EL;i++)addE(E[i].fi,E[i].se);
    memset(v2,0,sizeof v2);
    S=1e5;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)if(!v2[c[i][j]])
        {
            v2[c[i][j]]=1,ff2(c[i][j]);int U=0;
            for(int k=1;k<=T;k++)U=max(U,d[k]);
            if(a[i][j]!=(U&1))U++;
            S=min(S,U);
        }
    printf("%d\n",S);
    //while(ff());printf("%d\n",S);
    return 0;
}