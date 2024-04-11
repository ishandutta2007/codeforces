#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,ans=1,k;cin>>n>>k;
	while(k>0&&k%2==0)
	{
		k/=2;
		ans++;
	}
	cout<<ans;
}