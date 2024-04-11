#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,x,y,k;
bool check;
void binary(ll a,ll b)
{
	if(a>b)
	return ;
	ll mid=(a+b)/2;
	ll m=k*mid;
	if(m<=r&&m>=l)
	{
		check=1;
		return ;
	}
	else if(m<l)
	binary(mid+1,b);
	else if(m>r)
	binary(a,mid-1);
}
int main()
{
	cin>>l>>r>>x>>y>>k;
	binary(x,y);
	if(check)
	cout<<"YES";
	else
	cout<<"NO";
}