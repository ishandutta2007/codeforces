#include<bits/stdc++.h>
using namespace std;
int t,n,a[51];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool flag=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)
			if(a[i]+1<a[i+1])
			{
				puts("NO");
				flag=0;
				break;
			}
		if(flag)
			puts("YES");
	}
	return 0;
}