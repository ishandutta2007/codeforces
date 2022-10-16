#include <cstdio>
using namespace std;
int x,y,z,a,b,c;
int main()
{
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if (x>a)
	{
		printf("NO\n");
		return 0;
	}
	a-=x;
	if (a+b<y)
	{
		printf("NO\n");
		return 0;
	}
	if (a+b+c-y<z)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}