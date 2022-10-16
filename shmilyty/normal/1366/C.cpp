#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans,num0[61],num1[61],a;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		memset(num0,0,sizeof(num0));
		memset(num1,0,sizeof(num1));
		for(int i=1;i<=n;i++)
			for(int l=1;l<=m;l++)
			{
				scanf("%d",&a);
				if(a&1)
					num0[i+l-1]++;
				else
					num1[i+l-1]++;
			}
		for(int i=1;i*2<n+m;i++)
			ans+=min(num0[i]+num0[n+m-i],num1[i]+num1[n+m-i]);
		cout<<ans<<endl;
	}
	return 0;
}