#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
const int M=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		long long ans=0;
		long long tmp=0;
		long long times;
		cin>>n>>m;
		times=n/m;
		for (int i=1;i<=10;i++)
		{
			tmp+=(m*i)%10;
		}
		ans+=(times/10)*tmp;
		for (int i=1;i<=times%10;i++)
		{
			ans+=(m*i)%10;
		}
		cout<<ans<<endl;
	}
}