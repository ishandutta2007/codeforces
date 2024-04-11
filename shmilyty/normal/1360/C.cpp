#include<bits/stdc++.h>
using namespace std;
int t,n,s,m,a[51];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=m=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i]%2;
			m+=1-a[i]%2;
		}
		if(s%2==0)
			puts("YES");
		else
		{
			sort(a+1,a+1+n);
			bool flag=1;
			for(int i=1;i<n;i++)
				if(a[i+1]==a[i]+1)
				{
					flag=0;
					puts("YES");
					break;
				}
			if(flag)
				puts("NO");
		}
	}
	return 0;
}