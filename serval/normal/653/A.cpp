#include <cstdio>
using namespace std;
int n,i,t;
bool s[1001];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&t);
		s[t]=1;
	}
	for (i=1;i<=998;i++)
		if (s[i]&&s[i+1]&&s[i+2])
			break;
	if (i<=998)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}