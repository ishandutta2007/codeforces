#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int k = (2 * n + 1) / 3;
	printf("%d\n", k);
	
	if(k & 1)
	{
		for(int i = 1; i <= k; i++)
		{
			printf("%d %d\n", i, 1 + (2 * i - 2) % k);
		}
	}
	else
	{
		int l = k / 2;
		for(int i = 1; i <= l; i++)
		{
			printf("%d %d\n", i, 2 * i - 1);
		}
		for(int i = 1; i <= l; i++)
		{
			printf("%d %d\n", i + l, 2 * i);
		}
	}

	return 0;
 }