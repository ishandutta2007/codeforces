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

const int N=10000+2000+19,M=2000000,oo=(1<<30)-1;
struct Edge {int y,f,nxt;} E[M];
int Last[N],A[N],Q[N],Dis[N];
int n,m,g,cnt,S,T,k,x,Ans;

void Add_Edge(int x,int y,int f)
{
	E[cnt]=(Edge){y,f,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,0,Last[y]};Last[y]=cnt++;
}

bool BFS()
{
	memset(Dis,-1,sizeof(Dis));Dis[S]=1;
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
			int tmp=Dinic(E[i].y,min(Flow,E[i].f));
			E[i].f-=tmp,E[i^1].f+=tmp,Flow-=tmp,res+=tmp;
		}
	if (!res) Dis[x]=-1;
	return res;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN(),g=IN();
	S=n+m+1,T=S+1;
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) A[i]?Add_Edge(S,i,IN()):Add_Edge(i,T,IN());
	For(i,1,m+1)
		if (IN())
		{
			Add_Edge(S,i+n,x=IN());Ans+=x;
			for (k=IN();k--;) Add_Edge(i+n,IN(),oo);
			if (IN()) Add_Edge(S,i+n,g);
		} else
		{
			Add_Edge(i+n,T,x=IN());Ans+=x;
			for (k=IN();k--;) Add_Edge(IN(),i+n,oo);
			if (IN()) Add_Edge(i+n,T,g);
		}
	while (BFS()) Ans-=Dinic(S,oo);
	printf("%d\n",Ans);
}