#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,x,ans=0x7fffffff;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			ans&=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}