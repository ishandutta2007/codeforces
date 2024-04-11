#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100000+19,P=1e9+7;
struct Link {int x,y,f;} L[N];
struct Edge {int y,nxt;} E[N*2];
int Fa[N],Last[N],vis[N],n,m,Ans=1,cnt;

int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}
void Add_Edge(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,Last[y]};Last[y]=cnt++;
}
int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}
void Union(int x,int y)
{
	int fx=Getf(x),fy=Getf(y);
	if (fx!=fy) Fa[fx]=fy;
}
void DFS(int x,int c)
{
	vis[x]=c;
	for (int i=Last[x];~i;i=E[i].nxt)
		if (vis[E[i].y])
		{
			if (vis[E[i].y]!=(c^3)) {puts("0");exit(0);}
		} else DFS(E[i].y,c^3);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN();
	For(i,1,n+1) Fa[i]=i;
	For(i,0,m) L[i]=(Link){IN(),IN(),IN()};
	For(i,0,m) if (L[i].f==1) Union(L[i].x,L[i].y);
	For(i,0,m) if (L[i].f==0) Add_Edge(Getf(L[i].x),Getf(L[i].y));
	For(i,1,n+1)
		if (Fa[i]==i&&!vis[i]) Ans=2*Ans%P,DFS(i,1);
	printf("%d\n",1LL*Ans*Pow(2,P-2)%P);
}