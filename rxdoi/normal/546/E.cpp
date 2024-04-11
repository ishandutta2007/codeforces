#include<cstdio>
#include<cctype>
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

const int N=200+19,M=N*N*2,oo=(1<<30)-1;
struct Edge {int y,t,f,nxt;} E[M];
int Dis[N],Q[N],Last[N],Res[N][N];
int n,m,S,T,Ans,cnt,x,y,Sum1,Sum2;

void Add_Edge(int x,int y,int f)
{
	E[cnt]=(Edge){y,f,f,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,0,0,Last[y]};Last[y]=cnt++;
}

bool BFS()
{
	memset(Dis,-1,sizeof(Dis));Dis[S]=0;
	int f=1,w=0;Q[1]=S;
	while (f>w)
	{
		int x=Q[++w];
		for (int i=Last[x];~i;i=E[i].nxt)
			if (E[i].f&&Dis[E[i].y]==-1) Dis[E[i].y]=Dis[x]+1,Q[++f]=E[i].y;
	}
	return Dis[T]!=-1;
}
int Dinic(int x,int Flow)
{
	if (x==T||!Flow) return Flow;
	int res=0;
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].f&&Dis[E[i].y]==Dis[x]+1)
		{
			int tmp=Dinic(E[i].y,min(E[i].f,Flow));
			res+=tmp,Flow-=tmp,E[i].f-=tmp,E[i^1].f+=tmp;
		}
	if (!res) Dis[x]=-1;
	return res;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	S=2*n+1,T=S+1;
	For(i,1,n+1) scanf("%d",&x),Add_Edge(S,i,x),Sum1+=x;
	For(i,1,n+1) scanf("%d",&x),Add_Edge(i+n,T,x),Sum2+=x;
	if (Sum1!=Sum2) return puts("NO"),0;
	For(i,0,m) scanf("%d%d",&x,&y),Add_Edge(x,y+n,oo),Add_Edge(y,x+n,oo);
	For(i,1,n+1) Add_Edge(i,i+n,oo);
	while (BFS()) Ans+=Dinic(S,oo);
	for (int i=Last[S];~i;i=E[i].nxt) if (E[i].f) return puts("NO"),0;
	puts("YES");
	for (x=1;x<=n;x++)
		for (int i=Last[x];~i;i=E[i].nxt)
			if (E[i].y>n) Res[x][E[i].y-n]=E[i].t-E[i].f;
	for (int i=1;i<=n;i++,puts(""))
		For(j,1,n+1) printf("%d ",Res[i][j]);
}