#include<stdio.h>
#include<string.h>
main()
{
	char rc[1001],bc[1001];
	int cntr,cntb,t,i,n;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d\n",&n);
		cntr=cntb=0;
		gets(rc);
		gets(bc);
		for(i=0;i<n;i++)
		{
			if(rc[i]>bc[i])cntr++;
			else if(rc[i]<bc[i]) cntb++;
		}
		if(cntr>cntb)printf("RED\n");
		else if(cntr==cntb)printf("EQUAL\n");
		else printf("BLUE\n");
	}
}