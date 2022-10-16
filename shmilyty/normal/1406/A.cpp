#include<bits/stdc++.h>//2
using namespace std;
int t,n,fir,a,ans,num[101];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fir=ans=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			num[a]++;
		}
		for(int i=0;i<=100;i++)
		{
			if(fir==0&&num[i]<=1)
			{
				ans+=i;
				fir=1;
			}
			if(fir&&num[i]==0)
			{
				ans+=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}