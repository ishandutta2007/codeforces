#include<bits/stdc++.h>
using namespace std;
char a[123456];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		cin >> a;
		int flag = n;
		for(int i = 1; i < n; i++)
		{
			if(a[i] > a[i - 1]) 
			{
				flag = i;
				break;
			}
		}
		if(n == 1 || a[0] == a[1]) printf("%c%c\n", a[0], a[0]);

		else
		{
			for(int i = 0; i < flag; i++)
			{
				printf("%c", a[i]);
			}
			for(int i = flag - 1; i >= 0; i--)
			{
				printf("%c", a[i]);
			}
			printf("\n");
		}
	}

	return 0;
}