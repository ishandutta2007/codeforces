#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int Maxn=2e6+19;
struct Edge {int y,nxt;} E[Maxn*2];
vector<int> P[Maxn],tmp[Maxn];
int n,Q,cnt,x,y,opt;
int A[Maxn],Ans[Maxn],Fa[Maxn],Deep[Maxn],Last[Maxn],is_p[Maxn];

inline void Link(int x,int y) 
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
}
inline void pre_DFS(int x)
{
	for (int i=Last[x];i!=-1;i=E[i].nxt)
		if (E[i].y!=Fa[x]) Fa[E[i].y]=x,Deep[E[i].y]=Deep[x]+1,pre_DFS(E[i].y);
}
inline void DFS(int x)
{
	for (int i=0;i<P[A[x]].size();i++) 
	{
		int p=P[A[x]][i];
		if (tmp[p].size()) 
			if (Deep[Ans[x]]<Deep[tmp[p][tmp[p].size()-1]]) Ans[x]=tmp[p][tmp[p].size()-1];
		tmp[p].push_back(x);
	}
	for (int i=Last[x];i!=-1;i=E[i].nxt) 
		if (E[i].y!=Fa[x]) DFS(E[i].y);
	for (int i=0;i<P[A[x]].size();i++) tmp[P[A[x]][i]].pop_back();
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Link(x,y),Link(y,x);
	memset(is_p,1,sizeof(is_p));
	for (int i=2;i<Maxn;i++)
		if (is_p[i])
			for (int j=i;j<Maxn;j+=i) 
				P[j].push_back(i),is_p[j]=0;
	Deep[0]=-1;
	pre_DFS(1);
	DFS(1);
	while (Q--)
	{
		scanf("%d%d",&opt,&x);
		if (opt==1) printf("%d\n",Ans[x]?Ans[x]:-1);
			else scanf("%d",&y),memset(Ans,0,sizeof(Ans)),A[x]=y,DFS(1);
	}
}