#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}	
		for(int i = 0; i < n; i++)
		{
			if(i & 1) printf("%d ", -abs(a[i]));
			else printf("%d ", abs(a[i]));
		}
		printf("\n");
	}
	return 0;
}