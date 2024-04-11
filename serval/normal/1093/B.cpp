#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1005;
int t;
char s[N];
int l;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s+1);
		for (l=1;s[l+1];l++);
		sort(s+1,s+l+1);
		if (s[1]==s[l])
			printf("-1\n");
		else
			printf("%s\n",s+1);
	}
	return 0;
}