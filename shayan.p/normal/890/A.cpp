#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=(1<<6);
int main()
{
	ll a[7],num[7];
	for(ll i=0;i<6;i++)cin>>num[i];
	for(ll i=0;i<=maxn;i++)
	{
		ll cop=i,sum=0,x=0,y=0;
		for(ll j=0;j<6;j++){a[j]=cop%2;cop/=2;sum+=a[j];}
		if(sum!=3)continue;
		for(ll j=0;j<6;j++)if(a[j])x+=num[j];else y+=num[j];
		if(x==y){cout<<"YES";return 0;}
	}
	cout<<"NO";
}