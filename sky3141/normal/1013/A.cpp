#include <cstdio>

using namespace std;

int n;
int sa, sb;

int main()
{
	int tmp;
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &tmp);
		sa += tmp;
	}
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &tmp);
		sb += tmp;
	}
	if(sa >= sb) printf("YES");
	else printf("NO");
	return 0;
}