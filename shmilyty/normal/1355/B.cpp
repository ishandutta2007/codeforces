#include<bits/stdc++.h>
using namespace std;
int a[200001],tot[200001];
int main()
{
	int t,n,i,le,ans;
	cin>>t;
	while(t--)
	{
		ans=le=0;
		cin>>n;
		for(int i=1;i<=n;i++)
            tot[i]=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			tot[a[i]]++;
		}
		for(i=1;i<=n;i++)
		{
			ans+=(tot[i]+le)/i;
			le=(tot[i]+le)%i;
		}
		cout<<ans<<endl;
	}
	return 0;
}