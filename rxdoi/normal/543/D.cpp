#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=Last[x];~i;i=E[i].nxt) if (E[i].y!=Fa)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2e5+19,Mod=1e9+7;
struct Edge {int y,nxt;} E[N*2];
int Last[N],f[N],g[N],L[N],R[N],A[N];
int n,cnt,c;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%Mod) if (b&1) res=1LL*res*a%Mod;
	return res;
}

void DFS_1(int x,int Fa)
{
	f[x]=1;
	Rep(x) DFS_1(E[i].y,x),f[x]=1LL*f[x]*(f[E[i].y]+1)%Mod;
}
void DFS_2(int x,int Fa)
{
	c=0;
	Rep(x) A[++c]=f[E[i].y]+1;
	L[0]=R[c+1]=1;
	for (int i=1;i<=c;i++) L[i]=1LL*L[i-1]*A[i]%Mod;
	for (int i=c;i>=1;i--) R[i]=1LL*R[i+1]*A[i]%Mod;
	c=0;
	Rep(x) c++,g[E[i].y]=(1LL*g[x]*L[c-1]%Mod*R[c+1]%Mod+1)%Mod;
	Rep(x) DFS_2(E[i].y,x);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN();
	For(i,2,n+1) Link(i,IN());
	DFS_1(1,-1);
	g[1]=1,DFS_2(1,-1);
	For(i,1,n+1) printf("%d ",1LL*f[i]*g[i]%Mod);puts("");
}