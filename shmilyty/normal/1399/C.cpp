#include<bits/stdc++.h>
using namespace std;
int t,n,ans,res,a[51],num[101],nnum[101];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=100;i++)
		{
			res=0;
			for(int l=1;l<=n;l++)
				nnum[l]=num[l];
			for(int l=1;l<=n;l++)
			{
				if(a[l]>=i)
					break;
				if(a[l]==i-a[l])
					res+=nnum[a[l]]/2;
				else
					res+=min(nnum[a[l]],nnum[i-a[l]]);
				nnum[a[l]]=nnum[i-a[l]]=0;
			}	
			ans=max(res,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}