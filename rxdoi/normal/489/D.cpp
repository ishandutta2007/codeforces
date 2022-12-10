#include<cstdio>
#include<cctype>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=3000+19,M=30000+19;

struct Graph
{
	struct Edge {int y,nxt;} E[M];
	int Last[N],cnt;
	Graph() {memset(Last,-1,sizeof(Last));cnt=0;}	
	void Add_Edge(int x,int y) {E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;}
} G,P;

int A[N],n,m,x,y,Ans;

int main()
{
	n=IN(),m=IN();
	For(i,0,m) x=IN(),y=IN(),G.Add_Edge(x,y),P.Add_Edge(y,x);
	for (x=1;x<=n;x++)
	{
		for (int i=G.Last[x];~i;i=G.E[i].nxt) A[G.E[i].y]=x;
		for (y=1;y<=n;y++)
			if (x!=y)
			{
				int cnt=0;
				for (int i=P.Last[y];~i;i=P.E[i].nxt) cnt+=(A[P.E[i].y]==x);
				Ans+=cnt*(cnt-1)/2;
			}
	}
	printf("%d\n",Ans);
}