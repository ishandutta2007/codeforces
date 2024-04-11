#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<100)
		{
			cout<<n%10<<"\n";
		}
		else
		{
			int minn=10;
			while(n)
			{
				minn=min(minn,n%10);
				n/=10;
			}
			cout<<minn<<"\n";
		}
	}
	
	return 0;
}