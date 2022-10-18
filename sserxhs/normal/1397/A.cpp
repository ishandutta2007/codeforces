#include <stdio.h>
#include <string.h>
int cnt[26];
int n,i,c,t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			c=getchar();
			while ((c<'a')||(c>'z')) c=getchar();
			while ((c>='a')&&(c<='z'))
			{
				++cnt[c-'a'];c=getchar();
			}
		}c=0;
		for (i=0;i<=25;i++) if (cnt[i]%n) c=1;
		if (c==1) puts("NO"); else puts("YES");
	}
}