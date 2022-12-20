#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	ll M=max(a,b);
	ll m=min(a,b);
	if(m==0)
	return M;
	return gcd(M%m,m);
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=n/2;i>0;i--)
	{
		if(gcd(i,n-i)==1)
		{
			cout<<i<<" "<<n-i;
			break;
		}
	}
}