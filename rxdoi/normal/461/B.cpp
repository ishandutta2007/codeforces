#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e5+19,Mod=1e9+7;
typedef long long LL;
struct Edge {int y,nxt;} E[Maxn*2];
int n,p,A[Maxn];
LL F[Maxn][2];
int Last[Maxn],cnt;

inline void Add(int x,int y) 
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
}
inline LL Pow(LL a,LL b)
{
	LL tmp=a,Res=1LL;
	while (b)
	{
		if (b&1) (Res*=tmp)%=Mod;
		(tmp*=tmp)%=Mod;
		b>>=1;
	}
	return Res;
}
inline void DFS(int x)
{
	for (int i=Last[x];i!=-1;i=E[i].nxt) DFS(E[i].y);
	F[x][0]=F[x][1]=1;
	if (A[x]==1) 
	{
		F[x][0]=0;
		for (int i=Last[x];i!=-1;i=E[i].nxt) (F[x][1]*=1LL*(F[E[i].y][0]+F[E[i].y][1]))%=Mod;
	} else
	{
		F[x][1]=0;
		for (int i=Last[x];i!=-1;i=E[i].nxt) (F[x][0]*=1LL*(F[E[i].y][0]+F[E[i].y][1]))%=Mod;
		for (int i=Last[x];i!=-1;i=E[i].nxt) (F[x][1]+=(1LL*F[x][0]*Pow(F[E[i].y][0]+F[E[i].y][1],Mod-2)%Mod*1LL*F[E[i].y][1])%Mod)%=Mod;
	}
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d",&p),Add(p,i);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	DFS(0);
	printf("%I64d\n",F[0][1]);
}