#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n;


int main()
{
	scanf("%d",&n);
	for(int i=1,t=1;i<=n;i++)
	{
		for(int j=1;j<=n/2;j++)
		{
			printf("%d %d ",t,n*n-t+1);
			++t;
		}
		puts("");
	}
	return 0;
}