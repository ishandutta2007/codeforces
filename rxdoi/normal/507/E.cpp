#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
struct Edge {int y,z,c,nxt;} E[N*2];
struct Sol {int x,y,c;};
vector<Sol> V;
int Last[N],Q[50*N],pre[N],vis[N],cnt;
int n,m,x,y,c;
long long Dis[N];

void Link(int x,int y,int c)
{
	E[cnt]=(Edge){y,N+(c^1),c,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,N+(c^1),c,Last[y]};Last[y]=cnt++;
}
void SPFA()
{
	int f=1,w=0;Q[1]=1;pre[1]=-1;
	For(i,1,n+1) Dis[i]=1LL<<60;Dis[1]=0;
	while (f>w)
	{
		int x=Q[++w];vis[x]=0;
		for (int i=Last[x];~i;i=E[i].nxt)
			if (Dis[x]+E[i].z<Dis[E[i].y])
			{
				Dis[E[i].y]=Dis[x]+E[i].z;
				pre[E[i].y]=i;
				if (!vis[E[i].y]) vis[E[i].y]=1,Q[++f]=E[i].y;
			}
	}
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN();
	For(i,0,m) x=IN(),y=IN(),c=IN(),Link(x,y,c);
	SPFA();
	for (int i=pre[n];~i;i=pre[E[i^1].y])
	{
		if (!E[i].c) V.Pb((Sol){E[i^1].y,E[i].y,1});
		E[i].c=E[i^1].c=-1;
	}
	for (x=1;x<=n;x++)
		for (int i=Last[x];~i;i=E[i].nxt)
			if ((i&1)&&E[i].c==1) V.Pb((Sol){x,E[i].y,0});
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d %d %d\n",V[i].x,V[i].y,V[i].c);
}