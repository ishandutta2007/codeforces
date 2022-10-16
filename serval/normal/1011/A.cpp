#include <cstdio>
using namespace std;
int n,m,i,j;
char s[100];
int val[256];
int ans;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (i=1;i<=n;i++)
		val[s[i]]++;
	ans=0;
	for (i='a';i<='z';i++)
		if (val[i])
		{
			ans+=i-'a'+1;
			m--;
			if (m<=0)
				break;
			i++;
		}
	if (m>0)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}