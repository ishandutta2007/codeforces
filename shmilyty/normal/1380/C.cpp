#include<bits/stdc++.h>
using namespace std;
int t,a[100010];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,x,ans=0;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n,cnt=0;i;i--)
		{
			cnt++;
			if(cnt*a[i]>=x)
			{
				ans++;
				cnt=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}