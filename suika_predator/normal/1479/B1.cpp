#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333];
vector<int> L,R;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	L.push_back(1e9);
	R.push_back(1e9);
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	a[n+1]=114514;
	for(int i=1;i<=n;i++)
	{
		if(L.back()!=a[i])
		{
			if(R.back()!=a[i]&&R.back()==a[i+1])R.push_back(a[i]);
			else L.push_back(a[i]);
		}
		else if(R.back()!=a[i])R.push_back(a[i]);
		else L.push_back(a[i]),ans--;
	}
	cout<<ans<<endl;
	return 0;
}