#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int x;
		int ans=0;
		for(int i=1;i<=4;i++)cin>>x,ans+=x;
		if(ans==0)cout<<0<<endl;
		else if(ans==4)cout<<2<<endl;
		else cout<<1<<endl;
	}
	
	return 0;
}