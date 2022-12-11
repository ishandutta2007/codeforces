#include<cstdio>
#include<map>
using namespace std;

const int Maxn=1e5+19;
map<int,int> Map;
int can[Maxn][2],A[Maxn],Fa[Maxn],n,a,b;

inline int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}
inline void Union(int x,int y)
{
	int Fx=Getf(x),Fy=Getf(y);
	if (Fx!=Fy) 
	{
		Fa[Fx]=Fy;
		can[Fy][0]&=can[Fx][0];
		can[Fy][1]&=can[Fx][1];
	}
}

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),Map[A[i]]=i;
	for (int i=1;i<=n;i++) Fa[i]=i,can[i][0]=can[i][1]=1;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		x=Map[a-A[i]],y=Map[b-A[i]];
		if (x) Union(i,x);else can[Getf(i)][0]=0;
		if (y) Union(i,y);else can[Getf(i)][1]=0;
	}
	for (int i=1;i<=n;i++)
	{
		int x=Getf(i);
		if (!can[x][0]&&!can[x][1]) {puts("NO");return 0;}
	}
	puts("YES");
	for (int i=1;i<=n;i++) printf("%d ",can[Getf(i)][1]);
	puts("");
}