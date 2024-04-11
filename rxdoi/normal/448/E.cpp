#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19,Cnt=8500+19;
typedef long long LL;
struct Edge {int y,nxt;} E[Cnt*Cnt/3+19];
LL x,k,Div[Cnt];
int cnt,E_cnt,rest=1e5,Last[Maxn];

inline void Add_Edge(int x,int y)
{
	E[E_cnt]=(Edge){y,Last[x]};Last[x]=E_cnt++;
}
inline void DFS(int x,int k)
{
	if (rest==0) return;
	if (Div[x]==1||k==0)
	{
		printf("%I64d ",Div[x]);
		rest--;return;
	}
	for (int i=Last[x];i^-1;i=E[i].nxt) DFS(E[i].y,k-1);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%I64d%I64d",&x,&k);
	k=min(k,(LL)1e5);
	for (LL i=1;i*i<=x;i++) if (x%i==0) Div[cnt++]=i;
	for (int i=cnt-1;i>=0;i--) if (Div[i]*Div[i]^x) Div[cnt++]=x/Div[i];
	for (int i=0;i<cnt;i++)
		for (int j=i;j>=0;j--) if (Div[i]%Div[j]==0) Add_Edge(i,j);
	DFS(cnt-1,k);
}