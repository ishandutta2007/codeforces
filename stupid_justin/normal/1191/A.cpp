#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define MOD 1e9+7
#define inf 0x3f3f3f3f
using namespace std;
signed main()
{
	int n;
	cin>>n;
	if (n%4==1)
	{
		cout<<"0 A"<<endl;
	}
	else
	if (n%4==2)
	{
		cout<<"1 B"<<endl;
	}
	if (n%4==3)
	{
		cout<<"2 A"<<endl;
	}
	if (n%4==0)
	{
		cout<<"1 A"<<endl;
	}
}