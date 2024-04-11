#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
ll tw[30],ans;
bool buty(ll num)
{
	ll t=0;
	while(num%2==0){
		t++;
		num/=2;
	}
	if(num==tw[t+1]-1)return 1;
	return 0;
}
int main()
{
	tw[0]=1;for(ll i=1;i<=20;i++)tw[i]=tw[i-1]*2;
	ll n;cin>>n;
	for(ll i=1;i<=n;i++)
		if(n%i==0&&buty(i))ans=i;
	cout<<ans;
}