#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
typedef long long LL;
struct Edge {int y,nxt,ID;} E[N*2];
struct Link {int x,y,t;} L[N];
int Last[N],vis[N],D[N],Fa[N],S[N],tot[N][2],Tot[3],cnt,n,Max,m;
LL Ans;

void Add_Edge(int x,int y,int ID)
{
    E[cnt]=(Edge){y,Last[x],ID};Last[x]=cnt++;
    E[cnt]=(Edge){x,Last[y],ID};Last[y]=cnt++;
}

void DFS(int x)
{
    vis[x]=1;
    for (int i=Last[x];~i;i=E[i].nxt)
        if (!vis[E[i].y])
            L[E[i].ID].t=1,D[E[i].y]=D[x]+1,DFS(E[i].y);
}

int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}
void Union(int x,int y)
{
    int fx=Getf(x),fy=Getf(y);
    if (fx!=fy) Fa[fx]=fy;
}

void Solve_3()
{
    For(i,1,n+1) tot[Getf(i)][D[i]&1]++;
    For(i,1,n+1) For(j,0,2) Ans+=1LL*tot[i][j]*(tot[i][j]-1)/2LL;
    printf("1 %I64d\n",Ans);exit(0);
}
void Solve_2()
{
    For(i,1,n+1) Tot[S[i]]++;
    printf("2 %I64d\n",1LL*Tot[1]*Tot[2]+2LL*Tot[2]*(Tot[2]-1));
    exit(0);
}
void Solve_1()
{
    printf("3 %I64d\n",1LL*n*(n-1)*(n-2)/6LL);exit(0);
}

int main()
{
    memset(Last,-1,sizeof(Last));
    n=IN(),m=IN();
    For(i,1,n+1) Fa[i]=i;
    For(i,0,m) L[i]=(Link){IN(),IN()},Add_Edge(L[i].x,L[i].y,i),Union(L[i].x,L[i].y);
    For(i,1,n+1) Max=max(Max,++S[Getf(i)]);
    For(i,1,n+1) if (!vis[i]) DFS(i);
    For(i,0,m)
        if (!L[i].t)
            if ((D[L[i].x]&1)==(D[L[i].y]&1)) return puts("0 1"),0;
    if (Max>=3) Solve_3();
    if (Max==2) Solve_2();
    if (Max==1) Solve_1();
}