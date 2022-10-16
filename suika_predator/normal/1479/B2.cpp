#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333],num[233333],nx[233333];
vector<int> L,R;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	L.push_back(0);
	R.push_back(0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[i]=114514;
	}
	nx[0]=114514;
	for(int i=n;i>=1;i--)
	{
		nx[i]=num[a[i]];
		num[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<' '<<a[i]<<' '<<nx[i]<<endl;
		if(a[L.back()]==a[i])
		{
			L.push_back(i);
		}
		else if(a[R.back()]==a[i])R.push_back(i);
		else
		{
			ans++;
			if(nx[L.back()]<nx[R.back()])R.push_back(i);
			else L.push_back(i);
		}
	}
//	for(auto x:L)cout<<x<<' ';cout<<endl;
//	for(auto x:R)cout<<x<<' ';cout<<endl;
	cout<<ans<<endl;
	return 0;
}