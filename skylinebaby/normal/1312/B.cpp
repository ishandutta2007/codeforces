#include<bits/stdc++.h>
using namespace std;
int a[1254];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		reverse(a, a + n);
		for(int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");	
	}
	return 0;
 }