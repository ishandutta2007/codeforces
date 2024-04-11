#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[51];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=1e9;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)
			ans=min(ans,a[i+1]-a[i]);
		printf("%d\n",ans);
	}
	return 0;
}