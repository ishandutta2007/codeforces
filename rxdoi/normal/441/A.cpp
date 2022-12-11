#include<cstdio>
using namespace std;

const int Maxn=50+19;
int n,v,x,A[Maxn],cnt;

int main()
{
	scanf("%d%d",&n,&v);
	for (int i=1;i<=n;i++) 
	{
		int k,Flag=0;
		scanf("%d",&k);
		while (k--) 
		{
			scanf("%d",&x);
			if (x<v) Flag=1;
		}
		if (Flag) A[++cnt]=i;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",A[i]);puts("");
}