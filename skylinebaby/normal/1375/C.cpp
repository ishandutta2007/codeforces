#include<bits/stdc++.h>
using namespace std;
int a[312345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		if(a[0] < a[n - 1]) printf("YES\n");
		else printf("NO\n"); 
	}
	return 0;
}