#include<bits/stdc++.h>
using namespace std;
int T,x,y,k;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		if(x<y)
		{
			cout<<y-(y%x)/2<<endl;
		}
		else if(x==y)
		{
			cout<<x<<endl;
		}
		else
		{
			cout<<x+y<<endl;
		}
	}
	return 0;
}