#include<bits/stdc++.h>
using namespace std;
int a[312345]; 
int main()
{
	int n, ans = 0;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d",&a[i]);
	for(int i = 0;i<n;i++)
	{
		if(a[i]!=a[0]) ans = max(ans,i);
		if(a[i]!=a[n-1]) ans = max(ans,n-1-i);
	}
	printf("%d\n",ans);
	return 0;
 }