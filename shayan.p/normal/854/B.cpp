#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kaf(ll a)
{
	if(a%3==0)
	return a/3;
	else
	return (a/3)+1;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	if(n==k||k==0)
	{
		cout<<0<<" "<<0;
		return 0;
	}
	cout<<1<<" ";
	if(kaf(n)<=k)
	cout<<n-k;
	else
	cout<<2*k;
}