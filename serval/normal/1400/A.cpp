#include <cstdio>
using namespace std;
int t,n;
char s[105];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)
			printf("%c",s[2*i-1]);
		printf("\n");
	}
	return 0;
}