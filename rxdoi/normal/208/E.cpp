#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
typedef int one[N];
struct Edge {int y,nxt;} E[N*2];
struct Que {int L,R,ID;};
vector<Que> Q[N];
one Last,I,O,D;
vector<int> Rt,Pt[N];
int Fa[N][20],Ans[N],n,m,cnt,tot,p,x,y,Time;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void DFS(int x)
{
	I[x]=++tot;
	Pt[D[x]].Pb(x);
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].y!=Fa[x][0]) Fa[E[i].y][0]=x,D[E[i].y]=D[x]+1,DFS(E[i].y);
	O[x]=tot;
}
int Getf(int x,int k)
{
	for (int i=0;k;k>>=1,i++) if (k&1) x=Fa[x][i];
	return x;
}

one S,T;
void Add(int x,int v) {for (;x<=n;x+=x&-x) {if (T[x]!=Time) T[x]=Time,S[x]=0;S[x]+=v;}}
int Query(int x) {int Ans=0;for (;x;x-=x&-x) Ans+=T[x]!=Time?0:S[x];return Ans;}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN();
	For(i,1,n+1) if (x=IN()) Link(i,x);else Rt.Pb(i);
	For(i,0,Rt.size()) DFS(Rt[i]);
	for (x=1;x<20;x++) For(i,1,n+1) Fa[i][x]=Fa[Fa[i][x-1]][x-1];
	m=IN();
	For(i,0,m)
	{
		x=IN(),p=IN();
		if (p<=D[x]) y=Getf(x,p),Q[D[x]].Pb((Que){I[y],O[y],i});
	}
	For(i,0,n)
	{
		Time++;
		For(j,0,Pt[i].size()) Add(I[Pt[i][j]],1);
		For(j,0,Q[i].size()) Ans[Q[i][j].ID]=Query(Q[i][j].R)-Query(Q[i][j].L-1)-1;
	}
	For(i,0,m) printf("%d ",Ans[i]);puts("");
}