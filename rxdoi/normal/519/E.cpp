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

const int N=1e5+19;
struct Edge {int y,nxt;} E[N*2];
int Last[N],D[N],Fa[N][20],S[N];
int n,Q,cnt,x,y,z,Dis,k,Ans;

void Link(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
void DFS(int x)
{
	S[x]=1;
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].y!=Fa[x][0])
			Fa[E[i].y][0]=x,D[E[i].y]=D[x]+1,
			DFS(E[i].y),
			S[x]+=S[E[i].y];
}
int LCA(int x,int y)
{
	if (D[x]>D[y]) swap(x,y);
	for (int i=D[y]-D[x],k=0;i;i>>=1,k++) if (i&1) y=Fa[y][k];
	if (x==y) return x;
	for (int i=19;~i;i--) if (Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
	return Fa[x][0];
}
int Getf(int x,int D)
{
	for (int i=D,k=0;i;i>>=1,k++) if (i&1) x=Fa[x][k];
	return x;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN();
	For(i,1,n) Link(IN(),IN());
	DFS(1);
	for (x=1;x<20;x++)
		For(i,1,n+1) Fa[i][x]=Fa[Fa[i][x-1]][x-1];
	Q=IN();
	while (Q--)
	{
		x=IN(),y=IN(),z=LCA(x,y);
		if (x==y) {printf("%d\n",n);continue;}
		if ((Dis=D[x]-D[z]+D[y]-D[z])&1) {puts("0");continue;}
		if (D[x]>D[y]) Ans=S[Getf(x,Dis/2)]-S[Getf(x,Dis/2-1)];
		if (D[x]<D[y]) Ans=S[Getf(y,Dis/2)]-S[Getf(y,Dis/2-1)];
		if (D[x]==D[y]) Ans=n-S[Getf(x,Dis/2-1)]-S[Getf(y,Dis/2-1)];
		printf("%d\n",Ans);
	}
}