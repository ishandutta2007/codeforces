#include<cstdio>
using namespace std;

const int Maxn=1000+19;
int n,m,Ans,A[Maxn];
char c[Maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) 
	{
		scanf("%s",c);
		int s,g;
		for (int i=0;i<m;i++)
		{
			if (c[i]=='S') s=i;
			if (c[i]=='G') g=i;
		}
		if (g>s) {printf("-1\n");return 0;}
		A[s-g]=1;
	}
	for (int i=0;i<m;i++) Ans+=A[i];
	printf("%d\n",Ans);
}