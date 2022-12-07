#include<bits/stdc++.h>
using namespace std;
const int N=120;
int n,ans=0;
int a[N],vis[N];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		ans++;
		for(j=i;j<=n;j++)
		{
			if(a[j]%a[i]==0) vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}