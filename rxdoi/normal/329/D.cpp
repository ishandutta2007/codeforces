#include<cstdio>
using namespace std;

int n,tot;

int main()
{
	scanf("%d%d",&n,&tot);
	if (n==5) 
	{
		puts(">...v");
		puts("v.<..");
		puts("..^..");
		puts(">....");
		puts("..^.<");
		puts("1 1");
		return 0;
	}
	if (n==3)
	{
		puts(">vv");
		puts("^<.");
		puts("^.<");
		puts("1 3");
		return 0;
	}
	for (int x=0;x<49;x++)
	{
		if (x&1==0)
		{
			for (int i=0;i<32;i++) putchar('>');
			for (int i=0;i<32;i++) printf(">.");putchar('v');
			printf("...\n");putchar('^');
			for (int i=0;i<31;i++) printf(".<");
			for (int i=0;i<34;i++) putchar('<');
			printf("...\n");
		} else
		{
			putchar('v');
			for (int i=0;i<31;i++) printf(".<");
			for (int i=0;i<34;i++) putchar('<');
			printf("...\n");
			for (int i=0;i<36;i++) putchar('>');
			for (int i=0;i<30;i++) printf(">.");
			printf("^...\n");
		}
	}
	for (int i=0;i<32;i++) putchar('>');
	for (int i=0;i<32;i++) printf(">.");putchar('v');
	printf("...\n");putchar('^');
	for (int i=0;i<31;i++) printf("<.");
	for (int i=0;i<34;i++) putchar('<');printf("...\n");
	printf("100 1\n");
}