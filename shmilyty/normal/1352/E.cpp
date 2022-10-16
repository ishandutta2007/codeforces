#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[8001],f[8001],num[8001];
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
			f[i]=f[i-1]+a[i];
		} 
		for(int i=1;i<=n;i++)
			for(int l=i+1;l<=n;l++)
				if(f[l]-f[i-1]<=n)
					num[f[l]-f[i-1]]++;
		for(int i=1;i<=n;i++)
			if(num[a[i]])
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}