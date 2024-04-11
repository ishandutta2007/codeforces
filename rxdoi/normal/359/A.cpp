#include<cstdio>
using namespace std;

int n,m,x;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			scanf("%d",&x);
			if (x&&(i==0||i==n-1||j==0||j==m-1)) {puts("2");return 0;}
		}
	puts("4");
}