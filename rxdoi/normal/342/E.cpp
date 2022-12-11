#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int M=1e5+19,oo=(1<<30)-1;
struct Edge {int y,nxt;} E[M<<1];
vector<int> Red;
queue<int> Q;
int n,m,x,y,cnt,S;
int Last[M],Fa[M][21],Dis[M],Deep[M];

inline void Add_Edge(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
inline void DFS(int x)
{
	for (int i=Last[x];i^-1;i=E[i].nxt)
		if (E[i].y^Fa[x][0]) 
		{
			int y=E[i].y;Fa[y][0]=x;Deep[y]=Deep[x]+1;DFS(y);
		}
}
inline void Re_build()
{
	for (int i=0;i<Red.size();i++) Q.push(Red[i]);
	while (!Q.empty())
	{
		int x=Q.front();Q.pop();
		for (int i=Last[x];i^-1;i=E[i].nxt)
		{
			int y=E[i].y;
			if (Dis[x]+1<Dis[y]) {Dis[y]=Dis[x]+1;Q.push(y);}
		}
	}
	Red.clear();
}
inline int Mult_Lca(int x,int y)
{
	if (x==y) return x;
	if (Deep[y]<Deep[x]) swap(x,y);
	for (int i=20;i>=0;i--) if (Deep[Fa[y][i]]>Deep[x]) y=Fa[y][i];
	if (Fa[y][0]==x) return x;
	if (Deep[y]>Deep[x]) y=Fa[y][0];
	for (int i=20;i>=0;i--) if (Fa[x][i]^Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
	return Fa[x][0];
}

int main()
{
	memset(Dis,60,sizeof(Dis));
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Add_Edge(x,y);
	DFS(1);Dis[1]=0;
	Red.push_back(1);
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++) Fa[j][i]=Fa[Fa[j][i-1]][i-1];
	S=(int)sqrt(n)+1;
	while (m--)
	{
		scanf("%d%d",&x,&y);
		if (x==1)
		{
			Red.push_back(y);Dis[y]=0;
			if (Red.size()==S) Re_build();
		} else
		{
			int s=Red.size(),Ans=Dis[y];
			for (int i=0;i<s;i++) 
				Ans=min(Ans,Deep[y]+Deep[Red[i]]-2*Deep[Mult_Lca(y,Red[i])]);
			printf("%d\n",Ans);
		}
	}
}