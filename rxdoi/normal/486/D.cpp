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

const int N=2000+19,Mod=1e9+7;
struct Edge {int y,nxt;} E[N*2];
int Last[N],vis[N],f[N],A[N];
int D,n,cnt,Min,Max,Ans,T;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}

void DFS(int x,int Fa)
{
	f[x]=1;
	for (int i=Last[x];~i;i=E[i].nxt)
		if (vis[E[i].y]!=T&&E[i].y!=Fa&&A[E[i].y]>=Min&&A[E[i].y]<=Max)
			DFS(E[i].y,x),f[x]=1LL*f[x]*f[E[i].y]%Mod;
	f[x]=(f[x]+1)%Mod;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	D=IN(),n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n) Link(IN(),IN());
	For(i,1,n+1)
		if (!vis[i])
		{
			T++;
			Max=A[i],Min=A[i]-D;
			For(j,1,n+1)
				if (A[j]==A[i]&&vis[j]!=T) DFS(j,-1),(Ans+=(f[j]-1+Mod)%Mod)%=Mod,vis[j]=T;
		}
	printf("%d\n",Ans);
}