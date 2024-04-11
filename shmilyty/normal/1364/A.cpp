#include<bits/stdc++.h>
using namespace std;
int t,n,x,tot,ans1,ans2,a[100001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&x);
		tot=0;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%x)
				flag=0;
			a[i]%=x;
			tot+=a[i];
		}
		if(flag)
		{
			puts("-1");
			continue;
		}
		if(tot%x)
		{
			cout<<n<<endl;
			continue;
		}
		tot=0;
		ans1=0;
		while(tot%x==0)
		{
			ans1++;
			tot+=a[ans1];
		}
		tot=0;
		ans2=n;
		while(tot%x==0)
		{
			tot+=a[ans2];
			ans2--;
		}
		cout<<max(n-ans1,ans2)<<endl;
	}
	return 0;
}