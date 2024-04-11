#include<bits/stdc++.h>
using namespace std;
int t,n,f1[1001],f0[1001];
string s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		n=s.size();
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			f1[i]=f1[i-1];
			f0[i]=f0[i-1];
			if(s[i-1]=='1')
				f0[i]++;
			else
				f1[i]++;
		}
		for(int i=0;i<=n;i++)
			ans=min(ans,min(f1[i]+f0[n]-f0[i],f0[i]+f1[n]-f1[i]));
		cout<<ans<<endl;
	}
	return 0;
}