#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=200000+19;
struct Edge {int y,nxt;} E[Maxn<<1];
int A[Maxn],C[2][Maxn<<1],Last[Maxn],In[Maxn],Out[Maxn],Deep[Maxn];
int n,m,t,v,x,y,cnt,opt,tot;

inline void Add_Edge(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
}
inline void DFS(int x,int Fa)
{
	In[x]=++tot;
	for (int i=Last[x];i^-1;i=E[i].nxt) 
		if (E[i].y^Fa) {Deep[E[i].y]=Deep[x]+1;DFS(E[i].y,x);}
	Out[x]=++tot;
}
inline void Add(int k,int L,int R,int v)
{
	for (int x=R;x<=tot;x+=x&-x) C[k][x]+=v;
	if (L-1) for (int x=L-1;x<=tot;x+=x&-x) C[k][x]-=v;
}
inline int Query(int k,int a)
{
	int Ans=0;
	for (int x=tot;x;x-=x&-x) Ans+=C[k][x];
	for (int x=a-1;x;x-=x&-x) Ans-=C[k][x];
	return Ans;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);Add_Edge(y,x);
	}
	DFS(1,0);
	while (m--)
	{
		scanf("%d",&opt);
		if (opt==1)
		{
			scanf("%d%d",&t,&v);
			Add(Deep[t]&1,In[t],Out[t],v);
			Add(~Deep[t]&1,In[t],Out[t],-v);
		} else
		{
			scanf("%d",&t);
			printf("%d\n",A[t]+Query(Deep[t]&1,In[t]));
		}
	}
}