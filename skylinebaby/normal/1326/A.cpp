#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		if(n == 1)
		{
			printf("-1\n");
			continue;
		}
		printf("2");
		for(int i = 0; i < n - 1; i++) printf("3");
		printf("\n");		
	}

	return 0;
 }