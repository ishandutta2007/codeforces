#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
typedef long long LL;
const LL oo=(1LL<<60);
struct Edge {int y,nxt;} E[Maxn*2];
LL Ans,Inc[Maxn],Dec[Maxn];
int n,x,y,cnt,Last[Maxn],A[Maxn];

inline void Add(int x,int y) 
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
inline void DFS(int x,int Fa)
{
	LL _Inc=0,_Dec=0;
	for (int i=Last[x];i!=-1;i=E[i].nxt)
		if (E[i].y!=Fa)
		{
			int y=E[i].y;
			DFS(y,x);
			_Inc=max(_Inc,Inc[y]);
			_Dec=max(_Dec,Dec[y]);
		}
	A[x]=A[x]+_Inc-_Dec;
	Dec[x]=_Dec;Inc[x]=_Inc;
	if (A[x]>0) Dec[x]+=A[x];
	if (A[x]<0) Inc[x]-=A[x];
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),Add(x,y);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	DFS(1,0);
	printf("%I64d\n",Inc[1]+Dec[1]);
}