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

const int N=5000+19;
typedef long long LL;
struct Edge {int y,z,nxt;} E[N*2];
int Last[N],S[N];
int n,x,y,z,cnt,All;
LL Dis[N],Ans=1LL<<60,res,Min,tmp;

void Link(int x,int y,int z)
{
	E[cnt]=(Edge){y,z,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,z,Last[y]};Last[y]=cnt++;
}
void DFS1(int x,int Fa)
{
	S[x]=1,Dis[x]=0;
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].y!=Fa)
			DFS1(E[i].y,x),
			S[x]+=S[E[i].y],
			Dis[x]+=Dis[E[i].y]+1LL*E[i].z*S[E[i].y];
}
void DFS2(int x,int Fa)
{
	Min=min(Min,Dis[x]);
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].y!=Fa)
		{
			Dis[E[i].y]+=(Dis[x]-Dis[E[i].y]-1LL*E[i].z*S[E[i].y])+1LL*E[i].z*(All-S[E[i].y]);
			DFS2(E[i].y,x);
		}
}
void Solve(int x,int y,int z)
{
	res=tmp=0;
	DFS1(x,y),DFS1(y,x);
	Min=1LL<<60,All=S[x],DFS2(x,y);res+=Min*S[y];
	Min=1LL<<60,All=S[y],DFS2(y,x);res+=Min*S[x];
	For(i,1,n+1) tmp+=Dis[i];res+=tmp/2;
	res+=1LL*z*S[x]*S[y];
	Ans=min(Ans,res);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN();
	For(i,1,n) x=IN(),y=IN(),z=IN(),Link(x,y,z);
	for (x=1;x<=n;x++)
		for (int i=Last[x];~i;i=E[i].nxt) if (i&1) Solve(x,E[i].y,E[i].z);
	printf("%I64d\n",Ans);
}