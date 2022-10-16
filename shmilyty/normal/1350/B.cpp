#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[100001],f[100001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=1;
		memset(f,0,n*sizeof(int));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		f[1]=1;
		for(int i=2;i<=n;i++)
		{
			f[i]=1;
			for(int l=1;l*l<=i;l++)
				if(i%l==0)
				{
					if(a[i]>a[l])
						f[i]=max(f[i],f[l]+1);
					if(a[i]>a[i/l])
						f[i]=max(f[i],f[i/l]+1);
				}
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}