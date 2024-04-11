#include<stdio.h>
main()
{
	char s[105];
	int t,n,i,cnt;
	scanf("%d\n",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d\n",&n);
		gets(s);
		for(i=n-1;i>=0;i--)
		{
			if(s[i]==')')cnt++;
			else break;
		}
		if(2*cnt>n)puts("yes");
		else puts("no");
	}
}