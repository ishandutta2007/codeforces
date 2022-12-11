#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=2e5+19;
struct Edge {int y,z,nxt;} E[Maxn*2];
int F[Maxn],n,x,y,Last[Maxn],cnt,Min=Maxn,Ans;

inline void Add(int x,int y,int z) {E[cnt]=(Edge){y,z,Last[x]};Last[x]=cnt++;}
inline void DFS(int x,int Fa)
{
	for (int i=Last[x];i!=-1;i=E[i].nxt)
		if (E[i].y!=Fa) DFS(E[i].y,x),F[x]+=F[E[i].y]+E[i].z;
}
inline void Re_DFS(int x,int Fa)
{
	for (int i=Last[x];i!=-1;i=E[i].nxt) 
		if (E[i].y!=Fa) (F[E[i].y]=F[x]+(E[i].z==1?-1:1)),Re_DFS(E[i].y,x);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Add(y,x,1),Add(x,y,0);
	DFS(1,0);
	Re_DFS(1,0);
	for (int i=1;i<=n;i++) if (F[i]<Min) Min=F[i];
	printf("%d\n",Min);
	for (int i=1;i<=n;i++) if (F[i]==Min) printf("%d ",i);puts("");
}