#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int i,j=2,len,b=0,c;
	char a[110],d[110];
	scanf("%s",d);
	getchar();
	while(d[j]!='e')
	{
		j++;
	}
	for(i=0; i<j; i++)
	{
		a[i]=d[i];
	}
	len=j-2;
	c=strlen(d)-j-1;
	for(i=0; i<c; i++)
	{
		b+=((int)d[j+i+1]-48)*pow(10,c-i-1);
	}
	if(len>b)
	{
		for(i=0; i<b; i++)
		{
			a[i+1]=a[i+2];
			a[i+2]='.';
		}
		if(a[0]!='0'||b==0)
		{
			if((a[2]=='0')&& len==1)
			{
				printf("%c",a[0]);
			}
			else
			{
				for(i=0; i<len+2; i++)
				{
					printf("%c",a[i]);
				}
			}
		}
		else 
		{
			for(i=1; i<len+2; i++)
			{
				printf("%c",a[i]);
			}
		}
		
	}
	else 
	{
		for(i=0; i<b-len; i++)
		{
			a[len+i+2]='0';
		}
		if(a[0]!='0')
		{
			printf("%c",a[0]);
		}
	
		for(i=2; i<=b+1; i++)
		{
			printf("%c",a[i]);
		}
	}
	printf("\n");
	
	return 0;
}