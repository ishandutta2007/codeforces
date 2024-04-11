#include<bits/stdc++.h>
using namespace std;
int n,x,T;
int a[111111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		int maxx=0,ok=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxx=max(maxx,a[i]);
			if(x==a[i])ok=1;
		}
		if(ok)cout<<1<<endl;
		else if(x%maxx==0)cout<<x/maxx<<endl;
		else if(maxx>x)cout<<2<<endl;
		else cout<<x/maxx+1<<endl;
	}
	
	return 0;
}