#include <stdio.h>

int main()
{
	int t;
	int p;
	int n;
	char a[300000];
	char b[300000];
	int answer;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		scanf("%d", &n);
		scanf("%s", a);
		scanf("%s", b);
		answer = 0;
		for(int j=0; j<n; j++)
		{
			if(b[j] == '1')
			{
				if(j != 0 && a[j-1] == '1')
				{
					a[j-1] = '2';
					answer++;
				}
				else if(a[j] == '0')
				{
					a[j] = '2';
					answer++;
				}
				else if(j != n-1 && a[j+1] == '1')
				{
					a[j+1] = '2';
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}