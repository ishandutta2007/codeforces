#include<bits/stdc++.h>
using namespace std;
int a[12345];
int b[12345];

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
			scanf("%d", &b[i]);
		}
		sort(a, a + n);
		sort(b, b + n);
		for(int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
		for(int i = 0; i < n; i++) printf("%d ", b[i]);
		printf("\n");
	}
	return 0;
}