#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		if (n<=30) cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			if (n==36) cout<<"5 6 10 15"<<endl;else
			if (n==40) cout<<"5 6 14 15"<<endl;else
			if (n==44) cout<<"13 6 10 15"<<endl;else
			cout<<"6 10 14 "<<n-6-10-14<<endl;
		}
	}
}