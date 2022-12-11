#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxk=500+19,Maxn=1e5+19,oo=(1<<29)-1;
int n,m,k,x,y,co;
int c[Maxk],Dis[Maxk][Maxk],Fa[Maxn],tmp[Maxn];

inline int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) Fa[i]=i;
	for (int i=1;i<=k;i++) scanf("%d",&c[i]),c[i]+=c[i-1];
	for (int i=1;i<=k;i++) 
		for (int j=c[i-1]+1;j<=c[i];j++) tmp[j]=i;
	memset(Dis,60,sizeof(Dis));
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&x,&y,&co);
		int kx=tmp[x],ky=tmp[y];
		Dis[kx][ky]=Dis[ky][kx]=min(Dis[kx][ky],co);
		if (co==0)
		{
			int Fx=Getf(x),Fy=Getf(y);
			if (Fx^Fy) Fa[Fx]=Fy;
		}
	}
	for (int i=1;i<=k;i++)
		for (int j=c[i-1]+1;j<c[i];j++) 
			if (Getf(j)^Getf(j+1)) {printf("No\n");return 0;}
	for (int L=1;L<=k;L++)
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++) Dis[i][j]=min(Dis[i][j],Dis[i][L]+Dis[L][j]);
	for (int i=1;i<=k;i++) Dis[i][i]=0;
	printf("Yes\n");
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=k;j++) printf("%d ",Dis[i][j]>oo?-1:Dis[i][j]);
		printf("\n");
	}
}