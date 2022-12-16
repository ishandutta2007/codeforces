#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
using namespace std;
ll n;
set<ll>s;
void f(ll num)
{
	for(ll i=max(num,(ll)0);i<=n;i++)
	{
		ll cop=i;ll sum=0;
		while(cop>0)
		{
			sum+=cop%10;
			cop/=10;
		}
		if(sum+i==n)s.insert(i);
	}
}
int main()
{
	cin>>n;
	for(ll i=0;i<10;i++)f(n-9*i);
	cout<<s.size()<<endl;
	for(set<ll>::iterator it=s.begin();it!=s.end();it++)cout<<(*it)<<endl;
}