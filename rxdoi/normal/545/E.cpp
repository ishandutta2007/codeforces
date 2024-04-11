#include<cstdio>
#include<cctype>
#include<cstring>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=3e5+19,M=6e5+19;
typedef long long LL;
const LL oo=1LL<<60;
struct Edge {int y,z,ID,nxt;} E[M];
int Last[N],vis[N],pre[N],Q[100*N];
int n,m,x,y,z,cnt,S,tot,f,w;
LL Dis[N],Ans;
vector<int> V;

void Link(int x,int y,int z,int ID)
{
	E[cnt]=(Edge){y,z,ID,Last[x]};Last[x]=cnt++;
	E[cnt]=(Edge){x,z,ID,Last[y]};Last[y]=cnt++;
}
void SPFA(int S)
{
	For(i,0,n+1) Dis[i]=oo;Dis[S]=0;
	f=1,w=0;Q[1]=S;
	while (f>w)
	{
		int x=Q[++w];vis[x]=0;
		for (int i=Last[x];~i;i=E[i].nxt)
			if (Dis[x]+E[i].z<Dis[E[i].y])
			{
				Dis[E[i].y]=Dis[x]+E[i].z;
				pre[E[i].y]=i;
				if (!vis[E[i].y]) Q[++f]=E[i].y,vis[E[i].y]=1;
			} else
				if (Dis[x]+E[i].z==Dis[E[i].y]&&E[i].z<E[pre[E[i].y]].z) pre[E[i].y]=i;
	}
}

int main()
{
	memset(Last,-1,sizeof(Last));
	n=IN(),m=IN();
	For(i,0,m) x=IN(),y=IN(),z=IN(),Link(x,y,z,i+1);
	SPFA(S=IN());
	For(i,1,n+1) if (i!=S) V.push_back(E[pre[i]].ID),Ans+=E[pre[i]].z;
	printf("%I64d\n",Ans);
	For(i,0,V.size()) printf("%d ",V[i]);puts("");
}