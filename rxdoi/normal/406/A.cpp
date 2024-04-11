#include<cstdio>
using namespace std;

int n,m,x,c,Ans;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			scanf("%d",&x);
			if (i==j) Ans^=x;
		}
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d",&c);
		if (c<=2) scanf("%d",&x),Ans^=1;else printf("%d",Ans);
	}
	printf("\n");
}