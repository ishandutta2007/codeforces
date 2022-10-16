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
		if (n%4!=0)
		{
			for (int i=1;i<=n-(n+3)/4;i++) cout<<9;
			for (int i=1;i<=(n+3)/4;i++) cout<<8;cout<<endl;
		}
		if (n%4==0)
		{
			for (int i=1;i<=n/4*3;i++) cout<<9;
			for (int i=1;i<=n/4;i++) cout<<8;cout<<endl;
		}
	}
}