#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
#define Mp make_pair
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
struct Edge {int y,nxt;} E[N];
struct Event {int o,x,y;} Ev[N];
int Last[N],v[N],I[N],O[N],Fa[N],Ans[N];
int cnt,opt,n,Q,tot,cur,Qc,Qcc;
typedef pair<int,int> Pii;
vector<Pii> V[N];

int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}
void Add_Edge(int x,int y) {E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;}
void DFS(int x)
{
	I[x]=++tot;
	for (int i=Last[x];~i;i=E[i].nxt) DFS(E[i].y);
	O[x]=tot;
}
void Union(int x,int y)
{
	int fx=Getf(x),fy=Getf(y);
	if (fx!=fy) Fa[fx]=fy;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),Q=IN();
	For(i,1,Q+1)
	{
		Ev[i].o=IN(),Ev[i].x=IN();
		if (Ev[i].o!=2) Ev[i].y=IN();
		if (Ev[i].o==1) Add_Edge(Ev[i].y,Ev[i].x),v[Ev[i].x]=1;
		if (Ev[i].o==3) V[Ev[i].y].Pb(Mp(++Qc,Ev[i].x));
	}
	For(i,1,n+1) if (!v[i]) DFS(i);
	For(i,1,n+1) Fa[i]=i;
	For(i,1,Q+1)
	{
		if (Ev[i].o==1) Union(Ev[i].x,Ev[i].y);
		if (Ev[i].o==2)
		{
			int c=++Qcc,x=Ev[i].x,y;
			For(i,0,V[c].size())
				Ans[V[c][i].first]=(I[y=V[c][i].second]<=I[x]&&I[x]<=O[y]&&Getf(x)==Getf(y));
		}
	}
	For(i,1,Qc+1) puts(Ans[i]?"YES":"NO");
}