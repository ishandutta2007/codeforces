#include <stdio.h>

int main()
{
	int t;
	int p;
	int n;
	scanf("%d", &t);
	for(int j=0; j<t; j++)
	{
		scanf("%d", &p);
		n = p-1;
		for(int i=2; i*i<=p; i++)
		{
			if(n%i == 0)
			{
				printf("%d %d\n", i, n);
				break;
			}
		}
	}
}