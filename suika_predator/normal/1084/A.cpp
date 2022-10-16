#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans+=4*x*(i-1);
	}
	cout<<ans<<endl;
	return 0;
}