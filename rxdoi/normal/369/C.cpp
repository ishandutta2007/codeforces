#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e5+19;
struct Edge {int y,z,nxt;} E[Maxn*2];
int Last[Maxn],Ans[Maxn];
int n,x,y,z,cnt,tot;

inline void Link(int x,int y,int z) 
{
	E[cnt]=(Edge){y,z,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,z,Last[y]};Last[y]=cnt++;
}
inline int DFS(int x,int tmp,int Fa)
{
	int Flag=0;
	for (int i=Last[x];i!=-1;i=E[i].nxt) 
		if (E[i].y!=Fa) Flag|=DFS(E[i].y,E[i].z,x);
	if (!Flag&&tmp==2) Flag=1,Ans[++tot]=x;
	return Flag;
}

int main()
{
	scanf("%d",&n);
	memset(Last,-1,sizeof(Last));
	for (int i=1;i<n;i++) scanf("%d%d%d",&x,&y,&z),Link(x,y,z);
	DFS(1,1,0);
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",Ans[i]);
}