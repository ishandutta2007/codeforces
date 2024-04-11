#include<bits/stdc++.h>
using namespace std;
int col[5555];
long long s[5555],f[5555];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>col[i];
			f[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(col[i]!=col[j])
				{
					long long ti=f[i],tj=f[j];
					f[i]=max(f[i],tj+abs(s[i]-s[j]));
					f[j]=max(f[j],ti+abs(s[i]-s[j]));
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,f[i]);
		cout<<ans<<endl;
	}
	
	return 0;
}