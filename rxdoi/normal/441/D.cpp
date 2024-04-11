#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=3000+19;
int A[Maxn],f[Maxn],vis[Maxn];
int cnt,n,m,t;

inline int get_cir()
{
	int tmp=0;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (!vis[i]) {tmp++;for (int j=i;!vis[j];j=A[j]) vis[j]=1,f[j]=tmp;}
	return tmp;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	scanf("%d",&m);
	cnt=get_cir();
	printf("%d\n",t=abs(m-(n-cnt)));
	if (n-cnt<m) 
	{
		for (int i=1;i<=n&&t;i++)
			for (int j=i+1;j<=n&&t;j++)
				if (f[i]!=f[j])
				{
					printf("%d %d ",i,j);
					swap(A[i],A[j]);
					get_cir();t--;
				}
	} else
	{
		for (int i=1;i<=n&&t;i++)
			for (int j=i+1;j<=n&&t;j++)
				if (f[i]==f[j])
				{
					printf("%d %d ",i,j);
					swap(A[i],A[j]);
					get_cir();t--;
				}
	}
	puts("");
}