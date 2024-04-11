#include<bits/stdc++.h>
using namespace std;
int t,n,maxx,maxx_n,a[100001],num[100001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		maxx=maxx_n=0;
		for(int i=1;i<=n;i++)
			num[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			num[a[i]]++;
			if(num[a[i]]==maxx)
				maxx_n++;
			if(num[a[i]]>maxx)
			{
				maxx=num[a[i]];
				maxx_n=1; 
			}
		}
		cout<<(n-maxx_n*maxx)/(maxx-1)+maxx_n-1<<endl;	
	}
	return 0;
}