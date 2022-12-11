#include<cstdio>
using namespace std;

const int Maxn=3e5+19;
int L,R,x,n,m,Fa[Maxn],Ans[Maxn];

inline int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+1;i++) Fa[i]=i;
	while (m--)
	{
		scanf("%d%d%d",&L,&R,&x);
		for (int i=Getf(L);i<=R;i=Getf(i+1)) 
			if (x!=i) Ans[i]=x,Fa[i]=i+1;
	}
	for (int i=1;i<=n;i++) printf("%d ",Ans[i]);puts("");
}